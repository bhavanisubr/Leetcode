/**
 * You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
 */

class Solution {
public:
  void rotate(vector<vector<int> >& matrix) {
    // Clockwise rotation by 90 degrees.
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); i++) {  
      for (int j = 0; j < i; j++)
        swap(matrix[i][j], matrix[j][i]);
    }   
    
    // Anticlockwise rotation by 90 degrees.
    /*for (auto& rowIt : matrix) reverse(rowIt.begin(), rowIt.end());
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < i; j++)
        swap(matrix[i][j], matrix[j][i]);
    }*/
  }
};