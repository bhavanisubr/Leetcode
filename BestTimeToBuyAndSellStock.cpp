/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one 
 * share of the stock), design an algorithm to find the maximum profit.
 */

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int minSoFar = prices[0];
    int maxProfit = prices[1] - prices[0];
    for (int j = 1; j < prices.size(); j++) {
      maxProfit = max(maxProfit, prices[j] - minSoFar);
      minSoFar = min(minSoFar, prices[j]);
    }
    return maxProfit < 0 ? 0 : maxProfit;
  }
};