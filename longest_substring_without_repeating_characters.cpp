/**
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, 
 * "pwke" is a subsequence and not a substring.
 */

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    // O(n^2) time and O(n) space
    int longestSubstringLength = 0;
    for (int i = 0; i < s.length(); ++i) {
      map<char, bool> addedChars;
      addedChars[s[i]] = true;
      for (int j = i + 1; j < s.length(); ++j) {
        if (addedChars.find(s[j]) == addedChars.end()) {
          addedChars[s[j]] = true;
          continue;
        }
        break;
      }
      if (addedChars.size() > longestSubstringLength) longestSubstringLength = addedChars.size();
    }
    return longestSubstringLength;
  }
};
