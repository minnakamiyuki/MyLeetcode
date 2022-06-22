// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        int sell = 0, buy = -prices[0];
        for(int i = 1; i < prices.size(); i++) {
            sell = std::max(sell, buy + prices[i] - fee);
            buy = std::max(buy, sell - prices[i]);
        }
        return sell;
    }
};