/**
 * Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the 
 * two words do not share common letters. You may assume that each word will contain only lower case 
 * letters. If no such two words exist, return 0.
 *
 * Example 1:
 * Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 * Return 16
 * The two words can be "abcw", "xtfn".
 *
 * Example 2:
 * Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 * Return 4
 * The two words can be "ab", "cd".
 *
 * Example 3:
 * Given ["a", "aa", "aaa", "aaaa"]
 * Return 0
 * No such pair of words.
 */

class Solution {
public:
  int maxProduct(vector<string>& words) {
    // Using bit manipulation - O(n ^ 2) time.
    int maxProductSoFar = 0;
    if (words.size() <= 1)  return maxProductSoFar;
    vector<int> results(words.size(), 0);
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words[i].length(); j++) {
        int currentChar = words[i][j] - 'a';
        results[i] |= (1 << currentChar);
      }
    }
    for (int i = 0; i < words.size() - 1; i++) {
      for (int j = i + 1; j < words.size(); j++) {
        if ((results[i] & results[j]) == 0)
          maxProductSoFar = max(maxProductSoFar, (int)(words[i].length() * words[j].length()));
      }
    }
    return maxProductSoFar;
  }
};
