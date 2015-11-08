/**
 * Given an array of integers, every element appears three times except for one. Find that single one.
 */

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++) {
      ones = (ones ^ nums[i]) & ~twos;
      twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
  }
};
