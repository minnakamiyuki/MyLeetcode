// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int N = nums.size();
        int sum = 0;
        for (auto num : nums) sum += num;
        int target = sum - x;
        if (target < 0) return -1;
        int l = 0, r = 0, len = INT_MIN;
        while(r < N) {
            target -= nums[r++];
            while (target < 0) target += nums[l++];
            if (target == 0) len = max(len, r - l);
        }
        return len == INT_MIN ? -1 : N - len;
    }
};