/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
       stack<char> parenthesesStack;
       for (int i = 0; i < s.length(); i++) {
          if (s[i] == '(' || s[i] == '{' || s[i] == '[')   parenthesesStack.push(s[i]);
          else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
             if (parenthesesStack.empty())   return false;
             char top = parenthesesStack.top();
             if ((s[i] == ')' && top == '(') || (s[i] == ']' && top == '[') || (s[i] == '}' && top == '{')) {
                parenthesesStack.pop();
                continue;
             }
             return false;
          }
          else   return false;
       }
       if (parenthesesStack.empty())   return true;
       return false;
    }
};