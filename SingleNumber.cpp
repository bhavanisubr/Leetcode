/**
 * Given an array of integers, every element appears twice except for one. Find that single one.
 **/
 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       for (auto it = nums.begin(); it != nums.end(); ++it) {
          if (*it == *(++it))   continue;
          return *(it - 1);
       }
    }
};
