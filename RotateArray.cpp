/**
 * Rotate an array of n elements to the right by k steps.
 * For example: With n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 
*/

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    // Method 1:
    /*if (k <= 0) return;
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());*/
        
    // Method 2:
    for (int i = 0; i < k; i++) {
      nums.insert(nums.begin(), nums.back());
      nums.pop_back();
    }
  }
};