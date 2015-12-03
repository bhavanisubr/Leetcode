/**
 *  Given an unsorted array of integers, find the length of longest increasing subsequence.
 *
 *  For example: Given [10, 9, 2, 5, 3, 7, 101, 18], the longest increasing subsequence is [2, 3, 7, 101], 
 *  therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary 
 *  for you to return the length.
 *
 *  Your algorithm should run in O(n^2) complexity.
 *
 *  Follow up: Could you improve it to O(n log n) time complexity? 
 */

class Solution {
public:
  int getCeilIndex(vector<int>& maxLISLengthSoFar, int begin, int end, int key) {
    while (begin <= end) {
      int mid = begin + (end - begin) / 2;
      if (maxLISLengthSoFar[mid] == key)  return mid;
      if (maxLISLengthSoFar[mid] > key)  end = mid - 1;
      else  begin = mid + 1;
    }
  }

  int lengthOfLIS(vector<int>& nums) {
    // Method 1: Dynamic programming - O(n^2) time
    /*if (nums.empty())  return 0;
    vector<int> maxLISLengthSoFar(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[j] < nums[i])
          maxLISLengthSoFar[i] = max(maxLISLengthSoFar[j], maxLISLengthSoFar[i]);
      }
      ++maxLISLengthSoFar[i];
    }
    int overallMax = INT_MIN;
    for (int i = 0; i < maxLISLengthSoFar.size(); i++) {
      overallMax = max(overallMax, maxLISLengthSoFar[i]);
    }
    return overallMax;*/

    // Method 2: Binary search - O(n log n) time
    if (nums.empty())  return 0;
    vector<int> maxLISLengthSoFar(nums.size(), 0);
    maxLISLengthSoFar[0] = nums[0];
    int length = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < maxLISLengthSoFar[0])
        maxLISLengthSoFar[0] = nums[i];
      else if (nums[i] > maxLISLengthSoFar[length - 1])
        maxLISLengthSoFar[length++] = nums[i];
      else
        maxLISLengthSoFar[getCeilIndex(maxLISLengthSoFar, 0, length - 1, nums[i])] = nums[i];
    }
    return length;
  }
};
