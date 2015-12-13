/**
 * Given a string of numbers and operators, return all possible results from computing all the different 
 * possible ways to group numbers and operators. The valid operators are +, - and *.
 *
 * Example 1:
 * Input: "2-1-1"
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Output: [0, 2]
 *
 * Example 2:
 * Input: "2*3-4*5"
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) =  10
 * Output: [-34, -14, -10, -10, 10]
 */

class Solution {
public:
  vector<int> diffWaysToCompute(string input) {
    vector<int> out;
    for (int i = 0; i < input.size(); i++) {
      char curChar = input[i];
      if (curChar == '+' || curChar == '-' || curChar == '*') {
        vector<int> result1 = diffWaysToCompute(input.substr(0, i));
        vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
        for (int j = 0; j < result1.size(); j++) {
          for (int k = 0; k < result2.size(); k++) {
            if (curChar == '+')  out.push_back(result1[j] + result2[k]);
            if (curChar == '-')  out.push_back(result1[j] - result2[k]);
            if (curChar == '*')  out.push_back(result1[j] * result2[k]);
          }
        }
      }
    }
    if (out.empty())  out.push_back(stoi(input));
    return out;
  }
};
