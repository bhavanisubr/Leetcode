/**
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) 
 * which sum to n.
 *
 * For example: Given n = 12, return 3 because 12 = 4 + 4 + 4
 * Given n = 13, return 2 because 13 = 4 + 9.
 */

class Solution {
public:
  int numSquares(int n) {
    if (n <= 0)  return INT_MAX;
    vector<int> results(n + 1, 0);
    for (int i = 1; i < 4; i++)  results[i] = i;
    if (n < 4)  return results[n];
    for (int i = 4; i <= n; i++) {
      int num = sqrt(i);
      if (num * num == i) {
        results[i] = 1;
        continue;
      }
      int minSoFar = INT_MAX;
      for (int j = num; j >= 1; j--)
        minSoFar = min(minSoFar, results[j * j] + results[i - (j * j)]);
      results[i] = minSoFar;
    }
    return results[n];
  }
};
