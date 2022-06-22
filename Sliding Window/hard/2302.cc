// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0, res = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum * (i - j + 1) >= k)
                sum -= nums[j++];
            res += i - j + 1;
        }
        return res;
    }
};