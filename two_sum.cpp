/**
 * Given an array of integers, find two numbers such that they add up to a specific target number. The function 
 * twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less 
 * than index2. Please note that your returned answers (both index1 and index2) are not zero-based. You may assume 
 * that each input would have exactly one solution.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> outputIndices;
    map<int, int> numsMap;
    for (int i = 0; i < nums.size(); i++)  numsMap[nums[i]] = i;
    for (int i = 0; i < nums.size(); i++) {
      int curValComplement = target - nums[i];
      auto it = numsMap.find(curValComplement);
      if (it != numsMap.end() && it->second != i) {
        outputIndices.push_back(i + 1);
        outputIndices.push_back(it->second + 1);
        return outputIndices;
      }
    }
    return outputIndices;
  }
};
