/**
 * Given a sorted array, remove duplicates in-place such that each element appears at most twice and 
 * return the new length. Do not allocate extra space for another array, you must do this in-place with 
 * constant memory.
 * 
 * For example: Given sorted array nums = [1,1,1,2,2,3], your function should return length = 5, with the 
 * first five elements of nums being 1, 1, 2, 2 and 3. It does not matter what you leave beyond the new length. 
 */

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int length = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (length < 2 || nums[i] > nums[length - 2])
        nums[length++] = nums[i];
    }
    return length;
  }
};
