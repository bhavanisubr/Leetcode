/**
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * 
 * For example:
 * 1 -> A
 * 2 -> B
 * 3 -> C
 * ...
 * 26 -> Z
 * 27 -> AA
 * 28 -> AB  
*/

class Solution {
public:
  string convertToTitle(int n) {
    string out;
    while (n) {
      if (n % 26 == 0) {
        out.insert(out.begin(), 'Z');
        --(n /= 26);
      }
      else {
        out.insert(out.begin(), char(n % 26 - 1 + 'A'));
        n /= 26;
      }
    }
    return out;
  }
};