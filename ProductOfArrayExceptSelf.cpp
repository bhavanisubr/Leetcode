/**
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] 
 * is equal to the product of all the elements of nums except nums[i].
 * Solve it without division and in O(n).
 * 
 * For example: Given [1,2,3,4], return [24,12,8,6].
 * 
 * Follow up: Could you solve it with constant space complexity? (Note: The output array does not 
 * count as extra space for the purpose of space complexity analysis.) 
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> out(nums.size());
      for (int i = 0, prev = 1; i < nums.size(); prev *= nums[i], ++i)  out[i] = prev;
      for (int i = nums.size() - 1, prev = 1; i >= 0; prev *= nums[i], --i)  out[i] *= prev;
      return out;
    }
};