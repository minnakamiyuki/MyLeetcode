// https://leetcode.com/problems/minimum-size-subarray-sum/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int N = nums.size();
        int l = 0, r = 0, sum = 0, res = N + 1;
        while (l < N) {
            if (r < N && sum < target) {
                sum += nums[r++];
            } else {
                sum -= nums[l++];
            }
            if (sum >= target) {
                res = min(res, r - l);
            }
        }
        if (res == N + 1)
            return 0;
        return res;
    }
};