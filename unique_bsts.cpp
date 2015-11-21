/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * 
 * For example: Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 
 */

class Solution {
public:
  long getBinomialCoefficient(int n, int k) {
    if (k > n - k)  k = n - k;
    long res = 1;
    for (int i = 0; i < k; i++) {
      res *= n - i;
      res /= i + 1;
    }
    return res;
  }

  int numTrees(int n) {
    // NOTE: The number of structurally unique BSTs for a given n corresponds to the nth Catalan number (a sequence 
    // of natural numbers)
    
    // Method 1: Dynammic programming - O(n^2) time and O(n) space
    /*if (n < 0)  return INT_MAX;
    vector<int> results(n + 1, 0);
    results[0] = results[1] = 1;
    if (n <= 1)  return results[n];
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < i; j++)
        results[i] += results[j] * results[i - j - 1];
    }
    return results[n];*/

    // Method 2: Binomial coefficient - O(n) time and O(1) space
    if (n < 0)  return INT_MAX;
    if (n <= 1)  return 1;
    return getBinomialCoefficient(2 * n, n) / (n + 1);
  }
};
