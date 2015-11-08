/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 */

class Solution {
public:
  vector<pair<int, int> > getZeroCoordinates(vector<vector<int> >& matrix) {
    vector<pair<int, int> > out;
    for (int i = 0; i < matrix.size(); i++) {  
      for (int j = 0; j < matrix[i].size(); j++) {  
        if (matrix[i][j] == 0)  out.push_back(make_pair(i, j));
      }   
    }   
    return out;
  }

  void setZeroes(vector<vector<int> >& matrix) {
    vector<pair<int, int> > zeroCoordinates = getZeroCoordinates(matrix);
    for (auto& zc : zeroCoordinates) {
      int row = zc.first;
      int col = zc.second;
      for (int i = 0; i < matrix[0].size(); i++)  matrix[row][i] = 0;
      for (int i = 0; i < matrix.size(); i++)  matrix[i][col] = 0;
    }
  } 
};
