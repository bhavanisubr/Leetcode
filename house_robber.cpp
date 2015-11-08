/**
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money 
 * stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security 
 * system connected and it will automatically contact the police if two adjacent houses were broken into on the 
 * same night.
 * 
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum 
 * amount of money you can rob tonight without alerting the police.
 */

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty())  return 0;
    vector<vector<int>> maxProfit(nums.size(), vector<int>(nums.size(), 0));
    for (int i = 0; i < nums.size(); i++)  maxProfit[i][i] = nums[i];
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (j - 2 < 0)  maxProfit[i][j] = max(nums[j] + maxProfit[i][0], maxProfit[i][j - 1]);
        maxProfit[i][j] = max(nums[j] + maxProfit[i][j - 2], maxProfit[i][j - 1]);
      }
    }
    return maxProfit[0][nums.size() - 1];
  }
};
