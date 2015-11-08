/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string prefix;
    if (strs.empty())  return prefix;
    for (int i = 0; i < strs[0].size(); i++) {
      char currentChar = strs[0][i];
      for (int j = 1; j < strs.size(); j++)
        if (!strs[j][i] || currentChar != strs[j][i])  return prefix;
      prefix += currentChar;
    }
    return prefix;
  }
};
