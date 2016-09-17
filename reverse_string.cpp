/**
 * Write a function that takes a string as input and returns the string reversed.
 * Example: Given s = "hello", return "olleh".
 */

class Solution { 
public:
  string reverseString(string s) {
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j)  swap(s[i], s[j]);
    return s;
  }
};
