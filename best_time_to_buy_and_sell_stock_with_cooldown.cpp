/**
 * Say you have an array for which the ith element is the price of a given stock on day i. Design an algorithm 
 * to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share 
 * of the stock multiple times) with the following restrictions:
 *
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * 
 * Example: prices = [1, 2, 3, 0, 2], maxProfit = 3
 * i.e. the transactions are [buy, sell, cooldown, buy, sell]
 */

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // Dynamic programming - O(n) time and O(1) space.
    if (prices.size() <= 1)  return 0;
    int rest = 0, buy = -prices[0], sell = INT_MIN;
    for (int i = 1; i < prices.size(); i++) {
      buy = max(buy, rest - prices[i]);
      rest = max(rest, sell);
      sell = buy + prices[i];
    }
    return max(sell, rest);
  }
};
