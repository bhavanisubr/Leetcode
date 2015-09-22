/**
 * Given an integer n, return the number of trailing zeroes in n!.
 * Note: Your solution should have a logarithmic time complexity.
**/

class Solution {
public:
    int trailingZeroes(int n) {
       int count = 0;
       for (long factor = 5; n / factor > 0; factor *= 5)
          count += n / factor;
       return count;
    }
};
