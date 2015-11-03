/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example: Given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

class Solution {
public:
  vector<string> result;
  void generateParenthesisUtil(string str, int left, int right) {
    if (left == 0 && right == 0) {   
      result.push_back(str);
      return;
    }   
    if (left)  generateParenthesisUtil(str + '(', left - 1, right);
    if (right > left)  generateParenthesisUtil(str + ')', left, right - 1); 
  }

  vector<string> generateParenthesis(int n) {
    generateParenthesisUtil("", n, n); 
    return result;
  }
};