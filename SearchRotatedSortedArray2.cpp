/**
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * 
 * Note: Duplicates may be present in the array.
 */

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int begin = 0, end = nums.size() - 1;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (target == nums[mid])  return true;
      if (nums[mid] < nums[end]) {
        if (nums[mid] < target && nums[end] >= target)  begin = mid + 1;
        else  end = mid;
      }
      else if (nums[mid] > nums[end]) {
        if (nums[begin] <= target && nums[mid] > target)  end = mid;
        else  begin = mid + 1;
      }
      else  --end;
    }
    return nums[begin] == target;
  }
};