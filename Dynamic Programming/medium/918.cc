// https://leetcode.com/problems/maximum-sum-circular-subarray/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return nums[0];
        int sum = nums[0], sum1 = nums[0], ans1 = nums[0];
        for (int i = 1; i < n; ++i) {
            sum += nums[i];
            sum1 = nums[i] + max(sum1, 0);
            ans1 = max(ans1, sum1);
        }
        if (n == 2) return ans1;
        int sum2 = nums[0], ans2 = nums[0];
        for (int i = 1; i < n - 1; ++i) {
            sum2 = nums[i] + min(sum2, 0);
            ans2 = min(ans2, sum2);
        }
        ans2 = sum - ans2;
        return max(ans1, ans2);
    }
};