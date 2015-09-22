/**
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 **/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int slow = 0;
       for (int fast = 0; fast < nums.size(); fast++) {
          if (nums[fast] != val)   swap(nums[slow++], nums[fast]);
       }
       return slow;
    }
};
