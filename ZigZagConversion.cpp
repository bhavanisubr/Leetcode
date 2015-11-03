/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows 
 * like this:
   P   A   H   N
   A P L S I I G
   Y   I   R
 * and then read line by line: "PAHNAPLSIIGYIR"
 * 
 * i.e. Given a string and the number of rows, return a string that is written in a zigzag pattern
 * as described above.
 */

class Solution {
public:
  string convert(string s, int numRows) {
    string out;
    if (s.empty() || numRows <= 0)  return out;
    if (numRows == 1)  return s;
    
    vector<string> zigzag(numRows);
    bool flag = false;
    for (int i = 0, j = 0; i < s.length(); i++) {
      if (j == 0)  flag = false;
      if (!flag && j < numRows - 1) {
        zigzag[j++] += s[i];
        continue;
      }
      if (!flag && j == numRows - 1) {
        zigzag[j--] += s[i];
        flag = true;
        continue;
      }
      if (flag)  zigzag[j--] += s[i];
    }
    
    for (int i = 0; i < zigzag.size(); i++)  out += zigzag[i];
    return out;
  }
};
