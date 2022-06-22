// https://leetcode.com/problems/sum-of-total-strength-of-wizards/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 解法1：单调栈+前缀和

class Solution {
public:
    int totalStrength(vector<int>& s) {
        ll res = 0, sz = s.size(), mod = 1000000007;
        vector<int> st; // mono-increasing stack.
        vector<ll> pps(s.size() + 1);
        partial_sum(begin(s), end(s), begin(pps) + 1, [&](int s, int n){ return (s + n) % mod; });
        partial_sum(begin(pps), end(pps), begin(pps));
        for (int r = 0; r <= sz; ++r) {
            while(!st.empty() && (r == sz || s[st.back()] >= s[r])) {
                ll i = st.back(); st.pop_back();
                ll l = st.empty() ? -1 : st.back();
                res = (res + (mod + (pps[r] - pps[i]) * (i - l) % mod - (pps[i] - pps[max(0LL, l)]) * (r - i) % mod) * s[i]) % mod;
            }
            st.emplace_back(r);
        }
        return res;
    }
};

// 解法2：动态规划+前缀和

class Solution {
public:
    using ll = long long;
    int totalStrength(vector<int>& arr) {
        int n = arr.size(), res = 0, mod = 1e9+7;
        vector<ll> dp(n, 0),  minv(n, 0), sum(n, 0), aggsum(n,0);
        vector<ll> sk = {-1};
        for (int i = 0; i < n; ++i) {
            sum[i] = (i ? sum[i-1] : 0) + arr[i];
            aggsum[i] = (i ? aggsum[i-1] : 0) + (ll)arr[i]*(i+1);
            ll asum = 0, lsum = 0;
            while (sk.back() != -1 && arr[sk.back()] > arr[i]) {
                sk.pop_back();
            }
            lsum = sum[i] - (sk.back() == -1 ? 0 : sum[sk.back()]);
            asum = aggsum[i] - (sk.back() == -1 ? 0 : aggsum[sk.back()]);
            asum -= lsum*(sk.back()+1);
			
            ll last = sk.back() == -1 ? 0 : minv[sk.back()];
            minv[i] = last + (i-sk.back()) * arr[i];
			
            ll left = sk.back() == -1 ? 0 : ((minv[sk.back()]%mod)*(lsum%mod)%mod+dp[sk.back()]);
            ll right = ((ll)arr[i]*(asum%mod))%mod;
            dp[i] = (left+right)%mod;
			res = (res+dp[i]) % mod;
			
            sk.emplace_back(i);
        }
        return res;
    }
};