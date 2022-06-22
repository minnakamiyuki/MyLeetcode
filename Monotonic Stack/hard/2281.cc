// https://leetcode.com/problems/sum-of-total-strength-of-wizards/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
using P = pair<int, int>;

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