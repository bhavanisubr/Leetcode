/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has 
 * the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * 
 * For example: Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
 * Given target = 3, return true.
 */

class Solution {
public:
  int getRow(vector<vector<int> >& matrix, int begin, int end, int target) {
    int cols = matrix[0].size() - 1;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (target < matrix[mid][0])  end = mid - 1;
      else if (target >= matrix[mid][0] && target <= matrix[mid][cols])  return mid;
      else  begin = mid + 1;  
    }
    return end;
  }

  bool binarySearch(vector<vector<int> >& matrix, int row, int target) {
    int begin = 0, end = matrix[row].size() - 1;
    while (begin <= end) {   
      int mid = begin + (end - begin) / 2;
      if (target == matrix[row][mid])  return true;
      else if (target < matrix[row][mid])  end = mid - 1;
      else  begin = mid + 1;
    }   
    return false;
  }

  bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if (matrix.empty() && target)  return false;
    if (target > matrix[matrix.size() - 1][matrix[0].size() - 1])  return false;
    if (target < matrix[0][0])  return false;
    int row = getRow(matrix, 0, matrix.size() - 1, target);
    return binarySearch(matrix, row, target);
  }
};