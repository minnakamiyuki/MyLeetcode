// https://leetcode.com/problems/maximum-erasure-value/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int N = nums.size();
        int res = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0, j = 0; i < N; ++i) {
            int x = nums[i];
            mp[x]++;
            sum += x;
            while (mp[x] > 1) {
                sum -= nums[j];
                mp[nums[j]]--;
                j++;
            }
            res = max(res, sum);
        }
        return res;
    }
};