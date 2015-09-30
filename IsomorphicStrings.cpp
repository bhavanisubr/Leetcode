/**
 * Given two strings s and t, determine if they are isomorphic. 
 * Two strings are isomorphic if the characters in s can be replaced to get t. All occurrences of a character must be 
 * replaced with another character while preserving the order of characters. No two characters may map to the same 
 * character but a character may map to itself.
 * 
 * For example:
 * Given "egg", "add", return true.
 * Given "foo", "bar", return false.
 * Given "paper", "title", return true.
 * 
 * Note: You may assume both s and t have the same length.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
       map<char, char> charMap;
       vector<char> includedCharsVector;
       for (int i = 0; i < s.length(); i++) {
          if (!t[i])   return false;
          if (!charMap[s[i]]) {
             auto it = find(includedCharsVector.begin(), includedCharsVector.end(), t[i]);
             if (it != includedCharsVector.end())   return false;
             charMap[s[i]] = t[i];
             includedCharsVector.push_back(t[i]);
             continue;
          }
          if (t[i] != charMap[s[i]])  return false;
       }
       return true;
    }
};