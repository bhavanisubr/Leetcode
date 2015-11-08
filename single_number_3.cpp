/**
 * Given an array of numbers nums, in which exactly two elements appear only once and all the 
 * other elements appear exactly twice. Find the two elements that appear only once.
 * 
 * For example: Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 * 
 * Note: The order of the result is not important. So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity? 
 */

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int xorResult = 0;
    for (auto it : nums)  xorResult ^= it;
    int lastBitDiff = (xorResult & (xorResult - 1)) ^ xorResult;
    int group1 = 0, group2 = 0;
    for (auto it : nums) {
      if (it & lastBitDiff)  group1 ^= it;
      else  group2 ^= it;
    }
    return vector<int>{group1, group2};
  }
};
