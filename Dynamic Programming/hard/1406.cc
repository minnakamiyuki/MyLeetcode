// https://leetcode.com/problems/stone-game-iii/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int N = stoneValue.size();
        vector<int> dp(N + 1, -1e9);
        for (int i = N - 1; i >= 0; --i) {
            int sum = 0;
            for (int j = 0; j <= 2 && i + j < N; ++j) {
                sum += stoneValue[i + j];
                if (i + j == N - 1) {
                    dp[i] = max(dp[i], sum);
                } else {
                    dp[i] = max(dp[i], sum - dp[i + j + 1]);
                }
            }
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};