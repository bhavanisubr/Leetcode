/**
 * Given two binary strings, return their sum (also a binary string). 
 * For example, a = "11", b = "1". Return "100".
**/

class Solution {
public:
    string addBinary(string a, string b) {
       string out;
       if (a.empty() && b.empty())   return out;
       if (a.empty() || b.empty())   return (!a.empty() ? a : b);
       
       int lengthDiff = 0;
       if (a.length() > b.length()) {
          lengthDiff = a.length() - b.length();
          for (int i = 0; i < lengthDiff; i++)   b.insert(b.begin(), '0');
       }
       if (b.length() > a.length()) {
          lengthDiff = b.length() - a.length();
          for (int i = 0; i < lengthDiff; i++)   a.insert(a.begin(), '0');
       }
       
       int carry = 0;
       for (int i = a.length() - 1; i >= 0; i--) {
          int sum = carry + (a[i] - '0') + (b[i] - '0');
          out.insert(0, to_string(sum % 2));
          carry = sum / 2;
       }
       
       if (carry)   out.insert(0, to_string(carry));
       return out;
    }
};