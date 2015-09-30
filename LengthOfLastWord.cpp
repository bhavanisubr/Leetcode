/**
 * Given a string s consisting of upper/lower-case alphabets and empty space characters ' ', return the length of the
 * last word in the string. If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consisting of non-space characters only.
 * For example: Given s = "Hello World", return 5. 
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
       if (s.empty())   return 0;
       int slow = 0;
       for (int fast = 0; fast < s.length(); ) {
          while (fast < s.length() && s[fast] != ' ')   ++fast;
          while (fast < s.length() && s[fast] == ' ')   ++fast;
          if (fast != s.length())   slow = fast;
       }
       int count = 0;
       for (; slow < s.length() && s[slow] != ' '; ++slow, ++count);
       return count;
    }
};