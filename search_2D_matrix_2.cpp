/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following 
 * properties:
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * For example: Consider the following matrix:
 *
 * [
 *  [1,   4,  7, 11, 15],
 *  [2,   5,  8, 12, 19],
 *  [3,   6,  9, 16, 22],
 *  [10, 13, 14, 17, 24],
 *  [18, 21, 23, 26, 30]
 * ]
 *
 * Given target = 5, return true.
 * Given target = 20, return false.
 */

class Solution {
public:
  bool binarySearch(vector<vector<int>>& matrix, int row, int begin, int end, int target) {
    while (begin <= end) {
      int mid = begin + (end - begin) / 2;
      if (matrix[row][mid] == target)  return true;
      else if (matrix[row][mid] > target)  end = mid - 1;
      else  begin = mid + 1;
    }
    return false;
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Method 1: Time complexity - O(m + n), where m = numRows and n = numCols
    /*int numRows = matrix.size(), numCols = numRows ? matrix[0].size() : 0;
    for (int row = 0, col = numCols - 1; row < numRows && col >= 0; ) {
      if (matrix[row][col] == target)  return true;
      else if (matrix[row][col] > target)  --col;
      else  ++row;
    }
    return false;*/

    // Method 2: Binary search - O(m log n), where m = numRows and n = numCols
    int numRows = matrix.size(), numCols = numRows ? matrix[0].size() : 0;
    for (int i = 0; i < numRows; i++)
      if (binarySearch(matrix, i, 0, numCols - 1, target))  return true;
    return false;
  }
};
