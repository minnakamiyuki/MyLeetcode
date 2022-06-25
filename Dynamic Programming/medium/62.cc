// https://leetcode.com/problems/unique-paths/
#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> dp(110, 0);
        dp[1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};