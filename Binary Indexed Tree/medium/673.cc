// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val = 0;
    int cnt = 1;
    Node& operator+=(Node const& other) & {
        if (val > other.val) return *this;
        if (val < other.val) {
            val = other.val;
            cnt = other.cnt;
            return *this;
        }
        if (val > 0) cnt += other.cnt;
        return *this;
    }
};

class BIT {
public:
    vector<Node> tree;

    BIT(int n) : tree(n + 1) {}

    void update(int p, Node d) {
        const int n = tree.size();
        for (int i = p + 1; i < n; i += _low_bit(i))
            tree[i] += d;
    }

    Node prefixMax(int p) const {
        Node ans;
        for (int i = p; i > 0; i -= _low_bit(i))
            ans += tree[i];
        return ans;
    }
private:
    int _low_bit(int x) const {
        return x & (-x);
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int> const& nums) {
        vector<int> order(nums);
        sort(order.begin(), order.end());
        order.erase(unique(order.begin(), order.end()), order.end());
        const int n = nums.size();
        Node ans;
        BIT tree(n);
        for (const int e : nums) {
            const int rank = lower_bound(order.begin(), order.end(), e) - order.begin();
            auto prefix = tree.prefixMax(rank);
            prefix.val += 1;
            ans += prefix;
            tree.update(rank, prefix);
        }
        return ans.cnt;
    }
};
