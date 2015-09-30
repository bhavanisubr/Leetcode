/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * 
 * Note: You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold 
 * additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively. 
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i = 0, j = 0;
       for (; i < m && j < n; i++) {
          if (nums1[i] > nums2[j]) {
             swap(nums1[i], nums2[j]);
             // sort(nums2.begin(), nums2.end());
             for (int k = 0; k < n - 1 && nums2[k] > nums2[k + 1]; k++)   swap(nums2[k], nums2[k + 1]);
          }
       }
       while (j < n)   nums1[i++] = nums2[j++];
    }
};