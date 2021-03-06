/**
 * Find the contiguous subarray within an array (containing at least one number) which has 
 * the largest sum.
 * 
 * For example: Given the array [-2,1,-3,4,-1,2,1,-5,4], the contiguous subarray [4,-1,2,1] 
 * has the largest sum = 6.
 */

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int maxSumSoFar = INT_MIN, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum = sum >= 0 ? sum + nums[i] : nums[i];
      maxSumSoFar = max(maxSumSoFar, sum);
    }
    return maxSumSoFar;
  }
};
