/**
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be within 
 * the range from 1 to 3999.
 */

class Solution {
public:
  string intToRoman(int num) {
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string out;
    for (int i = 0; i < values.size(); i++) {
      while (num >= values[i]) {
        out += romans[i];
        num -= values[i];
      }
    }
    return out;
  }
};