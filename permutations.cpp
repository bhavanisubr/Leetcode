/**
 * Given a collection of numbers, return all possible permutations.
 * 
 * For example: [1,2,3] will have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

class Solution {
public:
  void permuteUtil(vector<int>& nums, int begin, int end, vector<vector<int>>& out) {
    if (begin == end) {   
      out.push_back(nums);
      return;
    }   
    for (int first = begin; first <= end; first++) {
      if (first > begin)  swap(nums[begin], nums[first]);
      permuteUtil(nums, begin + 1, end, out);
      if (first > begin)  swap(nums[begin], nums[first]);
    }   
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> out;
    permuteUtil(nums, 0, nums.size() - 1, out);
    return out;
  }
};
