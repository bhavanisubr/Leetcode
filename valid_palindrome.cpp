/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters 
 * and ignoring cases.
 * 
 * Examples: 
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 */

class Solution {
public:
  bool isPalindrome(string s) {
    if (s.empty())  return true;
    for (int first = 0, last = s.length() - 1; first <= last; ++first, --last) {
      while (first <= last && !isalnum(s[first]))  ++first;
      while (first <= last && !isalnum(s[last]))  --last;
      if (isalnum(s[first]) && isalnum(s[last]) && (tolower(s[first]) != tolower(s[last])))  
        return false;
    }
    return true;
  }
};
