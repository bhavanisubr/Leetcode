/**
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color 
 * are adjacent, with colors in the order red, white and blue respectively. Here, we use integers 0, 1, 
 * and 2 to represent colors red, white, and blue respectively.
 * 
 * Note: You are not supposed to use the library's sort function for this problem.
 */

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int redTail = 0, blueHead = nums.size() - 1;
    for (int i = 0; i <= blueHead; ) {   
      if (nums[i] == 0)  swap(nums[redTail++], nums[i++]);
      else if (nums[i] == 2)  swap(nums[blueHead--], nums[i]);
      else  ++i;
    }   
  }
};
