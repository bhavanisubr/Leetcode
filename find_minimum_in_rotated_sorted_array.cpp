/**
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 
 * 4 5 6 7 0 1 2). Find the minimum element. You may assume that no duplicates exist in the array. 
 */

class Solution {
public:
  int binarySearch(vector<int>& nums, int begin, int end) {
    while (nums[begin] > nums[end]) {
      int mid = begin + (end - begin) / 2;
      if (nums[mid] > nums[end])  begin = mid + 1;
      else  end = mid;
    }
    return nums[begin];
  }

  int findMin(vector<int>& nums) {
    return binarySearch(nums, 0, nums.size() - 1);
  }
};
