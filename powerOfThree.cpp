/*
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Follow up: Could you do it without using any loop / recursion?
 */

class Solution {
public:
  bool isPowerOfThree(int n) {
    // Method 1: Recursive solution
    //return n > 0 && (n == 1 || (n % 3 == 0 && isPowerOfThree(n / 3)));

    // Method 2: Iterative solution
    /*if (n > 1) {
      while (n % 3 == 0)  n /= 3;
    }
    return n == 1;*/

    // Method 3: O(1) time solution
    int maxPow3 = (int) pow(3, (int)(log(INT_MAX) / log(3)));
    return n > 0 && maxPow3 % n == 0;
  }
};
