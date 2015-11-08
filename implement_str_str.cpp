/**
 * Implement strStr(). That is, it returns the index of the first occurrence of needle in the haystack, 
 * or -1 if needle is not part of the haystack.
 */

class Solution {
public:
  int strStr(string haystack, string needle) {
    // Method: Brute force
    // Time : O(mn), where m = haystack length and n = needle length.
    if ((haystack.empty() && needle.empty() || (!haystack.empty() && needle.empty())))  return 0;
    if (haystack.length() < needle.length())  return -1;
    for (int i = 0, j = 0; i < needle.length() && j < haystack.length(); ++j) {
      int currentChar = needle[i];
      if (haystack[j] == currentChar) {
        int iTemp = i, jTemp = j;
        while (iTemp < needle.length() && jTemp < haystack.length() && haystack[jTemp] == needle[iTemp])    
          ++iTemp, ++jTemp;
        if (iTemp == needle.length())  return jTemp - needle.length();
        if (jTemp == haystack.length())  return -1;
      }
    }
    return -1;
  }
};
