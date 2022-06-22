// https://leetcode.com/problems/predict-the-winner/
#include <iostream>
#include <vector>
#include <functional>

class Solution {
public:
    bool PredictTheWinner(std::vector<int>& nums) {
        std::function<int(int, int)> S;
        const int n = nums.size();
        if (n <= 2 || !(n & 1)) return true;
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, -0x7fffffff));
        int i = 0, j = n - 1;
        S = [&](int i, int j) {
            if (dp[i][j] != -0x7fffffff) return dp[i][j];
            int res;
            if (i + 1 == j) {
                res = std::abs(nums[i] - nums[j]);
            } else {
                res = std::max(nums[i] - S(i + 1, j), nums[j] - S(i, j - 1));
            }
            dp[i][j] = res;
            return res;
        };
        return S(0, n - 1) >= 0;
    }
};