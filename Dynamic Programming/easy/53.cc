// https://leetcode.com/problems/maximum-subarray/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        int fn = nums[0];
        int res = nums[0];
        for(int i = 1; i < N; ++i) {
            fn = max(nums[i], fn + nums[i]);
            res = max(res, fn);
        }
        return res;
    }
};