/**
 * Determine whether an integer is a palindrome. Do this without extra space. 
 */

class Solution {
public:
  int reverse(int num) {
    int rev = 0;
    while (num) {
      rev = rev * 10 + num % 10;
      num /= 10;
    }
    return rev;
  }
  
  bool isPalindrome(int x) {
    if (x < 0)  return false;
    if (x == reverse(x))  return true;
    return false;
  }
};
