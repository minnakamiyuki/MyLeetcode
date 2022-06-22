// https://leetcode.com/problems/count-of-range-sum/
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int _n) : tree(n + 1), n(_n){};
    
    int lowbit(int x) { return x & -x; }
    
    void update(int x, int val) {
        while (x <= n) {
            tree[x] += val;
            x += lowbit(x);
        }
    }
    
    int getSum(int x) {
        int ans = 0;
        while (x) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
    
    int query(int x, int y) { return getSum(y + 1) - getSum(x); }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ll sums = 0;
        vector<ll> preSum = {0};
        for (auto &x : nums) {
            sums += x;
            preSum.emplace_back(sums);
        }
        
        set<ll> st;
        for (auto &x : preSum) {
            st.insert(x - lower);
            st.insert(x);
            st.insert(x - upper);
        }
        
        unordered_map<ll, int> mp;
        int c = 0;
        for (auto &x : st) {
            mp[x] = c++;
        }
        
        int res = 0;
        const int _n = mp.size();
        BIT t(_n + 4);
        for (auto &x : preSum) {
            int l = mp[x - upper], r = mp[x - lower];
            res += t.query(l, r);
            t.update(mp[x] + 1, 1);
        }
        return res;
    }
};