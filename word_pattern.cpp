/**
 * Given a pattern and a string str, find if str follows the same pattern. Here follow means a full match, 
 * such that there is a bijection between a letter in pattern and a non-empty word in str.
 * 
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * 
 * Note: You may assume pattern contains only lowercase letters, and str contains lowercase letters 
 * separated by a single space.
 */

class Solution {
public:
  bool wordPattern(string pattern, string str) {
    if (pattern.empty() && str.empty())  return true;
    if (pattern.empty() || str.empty())  return false;
    
    map<char, string> patternWordMap;
    vector<string> wordList;
    int i = 0, j = 0;
    for (; i < pattern.length() && j < str.length(); i++, j++) {
      string currentWord;
      for (; j < str.length() && str[j] != ' '; j++)  currentWord += str[j];
      if (patternWordMap[pattern[i]].empty()) {
        auto it = find(wordList.begin(), wordList.end(), currentWord);
        if (it != wordList.end())  return false;
        patternWordMap[pattern[i]] += currentWord;
        wordList.push_back(currentWord);
      }
      else if (patternWordMap[pattern[i]] != currentWord)  return false;
    }
    
    if (i < pattern.length() || j < str.length())  return false;
    return true;
  }
};
