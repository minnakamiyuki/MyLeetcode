// https://leetcode.com/problems/target-sum/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (target > sum) return 0;
        sum += target;
        if (sum & 1 || sum < 0) return 0;
        sum >>= 1;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (auto a : nums) {
            for (int i = sum; i >= a; --i) {
                dp[i] += dp[i - a];
            }
        }
        return dp[sum];
    }
};