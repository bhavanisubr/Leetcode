/**
 * A robot is located at the top-left corner of a m x n grid. The robot can only move either down or 
 * right at any point in time and it is trying to reach the bottom-right corner of the grid. How many 
 * possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 */

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int> > paths(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++) {   
      for (int j = 1; j < n; j++)
        paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
    }   
    return paths[m - 1][n - 1]; 
  }
};
