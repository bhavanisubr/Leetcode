/**
 * Given a non negative integer number num, for every number i in the range 0 ≤ i ≤ num, calculate the number of 1's in their binary 
 * representation and return them as an array.
 * 
 * Example: For num = 5 you should return [0,1,1,2,1,2].
 */

class Solution {
public:
  vector<int> countBits(int num) {
    /*
    // Method 1: Using GNU __builtin_popcount()
    vector<int> out = {0};
    for (int i = 1; i <= num; ++i)  out.push_back(__builtin_popcount(i));
    return out;

    // Method 2: Time complexity - O(n * sizeof(int))
    vector<int> out = {0};
    for (int i = 1; i <= num; ++i) {
      int count = 0, curNum = i;
      while (curNum) {
        count += (curNum & 1);
        curNum >>= 1;
      }
      out.push_back(count);
    }
    return out;
    */

    // Method 3: Time complexity - O(n)
    vector<int> out = {0};
    int count = 1;
    for (int i = 1; i <= num; ++i) {
      // Check if power of 2
      if ((i & i - 1) == 0) {
        out.push_back(1);
        count = 1;
        continue;
      }
      out.push_back(out[count++] + 1);
    }
    return out;
  }
};
