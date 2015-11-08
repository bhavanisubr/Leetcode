/**
 * A peak element is an element that is greater than its neighbors. Given an input array where num[i] is not equal 
 * to num[i+1], find a peak element and return its index. The array may contain multiple peaks. In that case, just 
 * return the index to any one of the peaks.
 * 
 * For example: in array [1, 2, 3, 1], 3 is a peak element and your function should return index number 2. 
 */

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int begin = 0, end = nums.size() - 1;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (nums[mid + 1] > nums[mid])  begin = mid + 1;
      else  end = mid;
    }
    return end;
  }
};
