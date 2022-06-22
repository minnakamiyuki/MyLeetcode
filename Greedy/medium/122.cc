// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int sum = 0;
        for(int i = 0; i < prices.size() - 1; i++) {
            int diff = prices[i + 1] - prices[i];
            if(diff > 0) {
                sum += diff;
            }
        }
        return sum;
    }
};