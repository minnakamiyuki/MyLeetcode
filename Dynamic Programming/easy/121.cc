// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size(), minp = 1e4, maxp = 0;
        for(int i = 0; i < len; i++) {
            minp = min(minp, prices[i]);
            maxp = max(maxp, prices[i] - minp);
        }
        return maxp;
    }
};