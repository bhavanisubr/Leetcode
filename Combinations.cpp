/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * For example: If n = 4 and k = 2, a solution is:
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */
 
class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > out;
    vector<int> temp(k, 0); 
    for (int i = 0; i >= 0; ) {  
      if (++temp[i] > n)  --i;
      else if (i == k - 1)  out.push_back(temp);
      else  temp[++i] = temp[i - 1]; 
    }
    return out;
  }
};