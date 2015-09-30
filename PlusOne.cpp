/**
 * Given a non-negative number represented as an array of digits, plus one to the number. The digits are stored such that 
 * the most significant digit is at the head of the list. 
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       vector<int> digitsPlusOne;
       int sum = 0, carry = 0;
       for (int i = digits.size() - 1; i >= 0; i--) {
          sum = (i == digits.size() - 1 ? digits[i] + 1 : digits[i] + carry);
          carry = sum / 10;
          digitsPlusOne.insert(digitsPlusOne.begin(), sum % 10);
       }
       if (carry)   digitsPlusOne.insert(digitsPlusOne.begin(), carry);
       return digitsPlusOne;
    }
};