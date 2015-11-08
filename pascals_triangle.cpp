/**
 * Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5, return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
] 
 */

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascalsTriangle;
    for (int i = 1; i <= numRows; i++) {
      vector<int> currentRow(i);
      currentRow.front() = 1, currentRow.back() = 1;
      for (int j = 1; j < currentRow.size() - 1; j++)   
        currentRow[j] = pascalsTriangle[i - 2][j - 1] + pascalsTriangle[i - 2][j];
      pascalsTriangle.push_back(currentRow);
    }
    return pascalsTriangle;
  }
};
