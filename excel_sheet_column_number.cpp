/**
 * Given a column title as appears in an Excel sheet, return its corresponding column number.
 * For example:
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28 
 */
 
class Solution {
public:
  int titleToNumber(string s) {
    map<char, int> charNumMap;
    int i = 1;
    for (char curChar = 'A'; curChar <= 'Z' && i <= 26; curChar++, i++)  charNumMap[curChar] = i;
    int number = 0;
    for (int i = s.length() - 1, power = 1; i >= 0; i--, power *= 26)  number += power * charNumMap[s[i]];
    return number;
  }
};
