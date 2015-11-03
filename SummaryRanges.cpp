/**
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * For example: Given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
*/

class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> out;
    if (nums.empty())  return out;
    if (nums.size() == 1) {
      string temp = to_string(nums[0]);
      out.push_back(temp);
      return out;
    }
    
    int slow = 0;
    for (int fast = 1; fast < nums.size(); fast++) {
      string temp = to_string(nums[slow]);
      bool foundRange = false;
      for (int i = 1; fast < nums.size() && nums[fast] - nums[slow] == i; ++fast, ++i)  foundRange = true;
      if (foundRange) {
        temp += "->";
        temp += fast == nums.size() ? to_string(nums[nums.size() - 1]) : to_string(nums[fast - 1]);
      }
      out.push_back(temp);
      slow = fast;
    }
    
    if (slow < nums.size()) {
      string temp = to_string(nums[slow]);
      out.push_back(temp);
    }
    return out;
  }
};