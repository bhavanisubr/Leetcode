/**
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 * For example:
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * Note: You may assume the string contains only lowercase alphabets.
 **/
 
class Solution {
public:
    bool isAnagram(string s, string t) {
       /* Solution 1:
       map<char, int> charCountMap;
       for (int i = 0; i < s.size(); i++)   ++charCountMap[s[i]];
       for (int i = 0; i < t.size(); i++) {
          auto it = charCountMap.find(t[i]);
          if (it->second == 0)   return false;
          --(it->second);
       }
       for (auto it = charCountMap.begin(); it != charCountMap.end(); it++)
          if (it->second) return false;
       return true; */
       
       // Solution 2:
       sort(s.begin(), s.end());
       sort(t.begin(), t.end());
       return s == t;
    }
};
