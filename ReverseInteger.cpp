/**
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321 
*/

class Solution {
public:
    int reverse(int x) {
       int rev = 0, temp = abs(x);
       while (temp) {
          if (rev > INT_MAX / 10 || rev < INT_MIN / 10)   return 0;
          rev = rev * 10 + temp % 10;
          temp /= 10;
       }
       if (x < 0)  rev = -rev;
       return rev;
    }
};