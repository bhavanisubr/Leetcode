/**
 * Given an index k, return the kth row of the Pascal's triangle.
 * For example: Given k = 3, return [1,3,3,1].
 * 
 * Note: Could you optimize your algorithm to use only O(k) extra space? 
 */

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> rowVector(rowIndex + 1);
    rowVector.front() = 1;
    rowVector.back() = 1;
    for (int i = 1; i < rowVector.size() - 1; i++)  
      rowVector[i] = (rowVector[i - 1] * (rowVector.size() - i)) / i;
    return rowVector;
  }
};
