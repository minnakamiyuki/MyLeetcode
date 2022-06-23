// https://leetcode.com/problems/minimum-falling-path-sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        const int n = matrix.size();
        auto Min = [](int &a, int &b, int &c) {
            int m;
            m = std::min(a, b);
            m = std::min(m, c);
            return m;
        };
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
                } else if (j == n - 1) {
                    dp[i][j] = matrix[i][j] + std::min(dp[i - 1][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = Min(dp[i - 1][j - 1], dp[i - 1][j + 1], dp[i - 1][j]) + matrix[i][j];
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            res = std::min(res, dp[n - 1][i]);
        }
        return res;
    }
};