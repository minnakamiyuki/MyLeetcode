// https://leetcode.com/problems/count-array-pairs-divisible-by-k/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

class Solution {
public:
    ll countPairs(vector<int>& nums, int k) {
        ll  res = 0;
        vector<pair<int, int>> factors;
        for (int i = 1; i * i <= k; ++i)
            if (k % i == 0) {
                factors.push_back({i, 0});
                if (k / i != i)
                    factors.push_back({k / i, 0});
            }
        for (int n : nums) {
            ll gcd_nk = __gcd(n, k);
        for (auto &factor : factors) {
            if (gcd_nk * factor.first % k == 0)
                res += factor.second;
            if (gcd_nk == factor.first)
                ++factor.second;
            }
        }
        return res;
    }
};