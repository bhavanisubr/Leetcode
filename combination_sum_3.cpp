/**
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 
 * can be used and each combination should be a unique set of numbers. Ensure that numbers within the set are 
 * sorted in ascending order.
 *
 * Example 1:
 * Input: k = 3, n = 7
 * Output:[[1,2,4]]
 * 
 * Example 2:
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 */

class Solution {
public:
  vector<vector<int>> out;
  vector<int> temp;
  void combinationSum3Helper(int k, int n, int highestNumSoFar) {
    if (k == 0 && n == 0) {
      out.push_back(temp);
      return;
    }
    for (int i = highestNumSoFar; i <= 10 - k && i <= n; i++) {
      temp.push_back(i);
      combinationSum3Helper(k - 1, n - i, i + 1);
      temp.pop_back();
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    combinationSum3Helper(k, n, 1); 
    return out;
  }
};
