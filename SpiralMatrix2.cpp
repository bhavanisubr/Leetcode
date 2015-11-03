/**
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * For example: Given n = 3, you should return the following matrix:
   [
     [ 1, 2, 3 ],
     [ 8, 9, 4 ],
     [ 7, 6, 5 ]
   ]
 */

class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > matrix(n, vector<int>(n));
    for (int i = 0, k = 1; k <= n * n; i++) {  
      for (int col = i; col < n - i; col++)  matrix[i][col] = k++;
      for (int row = i + 1; row < n - i; row++)  matrix[row][n - i - 1] = k++;
      for (int col = n - i - 2; col > i; col--)  matrix[n - i - 1][col] = k++;
      for (int row = n - i - 1; row > i; row--)  matrix[row][i] = k++;
    }
    return matrix;
  }
};