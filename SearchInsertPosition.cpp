/**
 * Given a sorted array and a target value, return the index if the target is found. If not, return 
 * the index where it would be if it were inserted in order.
 * 
 * You may assume that there are no duplicates in the array.
 * 
 * Here are few examples.
 * arr = [1,3,5,6], target = 5, output = 2
 * arr = [1,3,5,6], target = 2, output = 1
 * arr = [1,3,5,6], target = 7, output = 4
 * arr = [1,3,5,6], target = 0, output = 0
 */

class Solution {
public:
  int binarySearch(vector<int>& nums, int begin, int end, int target) {
    while (begin <= end) {   
      int mid = begin + (end - begin) / 2;
      if (target == nums[mid])  return mid;
      if (target < nums[mid])  end = mid - 1;
      else if (target > nums[mid])  begin = mid + 1;
    }   
    return begin;
  }
  
  int searchInsert(vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size() - 1, target);
  }
};