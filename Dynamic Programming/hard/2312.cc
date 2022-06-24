// https://leetcode.com/problems/selling-pieces-of-wood/
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using ll = long long;
class Solution {
public:
    ll dp[205][205];
    ll pp[205][205];
    bool vis[205][205];
    ll sellingWood(int m, int n, std::vector<std::vector<int>>& prices) {
        for (auto &x : prices) {
            pp[x[0]][x[1]] = x[2];
        }
        std::function<ll(int, int)> find = [&](int i, int j) {
            if (vis[i][j]) return dp[i][j];
            vis[i][j] = true;
            
            for (int l = 1; l <= j; ++l) {
                if (pp[i][l])
                    dp[i][j] = std::max(dp[i][j], pp[i][l] * (j / l));
            }
            for (int l = 1; l <= i; ++l) {
                if (pp[l][j])
                    dp[i][j] = std::max(dp[i][j], pp[l][j] * (i / l));
            }
            for (int l = 1; l <= (i >> 1); ++l) {
                dp[i][j] = std::max(dp[i][j], find(l, j) + find(i - l, j));
            }
            for (int l = 1; l <= (j >> 1); ++l) {
                dp[i][j] = std::max(dp[i][j], find(i, l) + find(i, j - l));
            }
            return dp[i][j];
        };
        return find(m, n);
    }
};