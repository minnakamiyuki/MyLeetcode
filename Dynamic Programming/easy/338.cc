// https://leetcode.com/problems/counting-bits/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;
    }
};