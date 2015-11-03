/**
 * Implement atoi() to convert a string to an integer.
 */

class Solution {
public:
  int myAtoi(string str) {
    if (str.empty())  return 0;
    bool isNegative = false;
    int i = 0, out = 0;
    for (; i < str.length() && str[i] == ' '; i++); 
    if (i + 1 < str.length() && str[i] == '-' && str[i + 1] != '+')  isNegative = true, ++i;
    else if (i + 1 < str.length() && str[i] == '+' && str[i + 1] != '-')  ++i;
    else if (i + 1 < str.length() && (str[i + 1] == '+' || str[i + 1] == '-'))  return 0;
    for (; i < str.length() && isdigit(str[i]); i++) {
      if (!isNegative && out > INT_MAX / 10)  return INT_MAX;
      if (!isNegative && out == INT_MAX / 10 && (str[i] - '0' >= 7))  return INT_MAX;
      if (isNegative && -out < INT_MIN / 10)  return INT_MIN;
      if (isNegative && -out == INT_MIN / 10 && (str[i] - '0' >= 8))  return INT_MIN;
      out = out * 10 + (str[i] - '0');
    }
    if (isNegative)  out = -out;
    return out;
  }
};