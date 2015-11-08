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
  int numTrees(int n) {
    if (n <= 0)  return INT_MAX;
    vector<int> results(n + 1, 1); 
    if (n == 1)  return results[n];
    for (int idx = 2; idx <= n; idx++) {   
      int out = 0;
      for (int i = 0; i < idx; i++) {   
        int leftRange = 1, rightRange = 1;
        if (i - 1)  leftRange = results[i];
        if (i + 1 < idx)  rightRange = results[idx - i - 1]; 
        out += leftRange * rightRange;
      }
      results[idx] = out;
    }
    return results[n];
  }
};
