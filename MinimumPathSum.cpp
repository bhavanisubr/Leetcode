/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
 * which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 */

class Solution {
public:
  int minPathSum(vector<vector<int> >& grid) {
    if (grid.empty())  return 0;
    vector<vector<int> > pathSum = grid;
    int rows = pathSum.size();
    int cols = pathSum[0].size();
    for (int i = 1; i < rows; i++)  pathSum[i][0] += pathSum[i - 1][0];
    for (int j = 1; j < cols; j++)  pathSum[0][j] += pathSum[0][j - 1]; 
    for (int i = 1; i < rows; i++) {   
      for (int j = 1; j < cols; j++)
        pathSum[i][j] += min(pathSum[i - 1][j], pathSum[i][j - 1]);
    }   
    return pathSum[rows - 1][cols - 1]; 
  }
};
