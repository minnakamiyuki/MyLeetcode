// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n = 20001;
    vector<int> tree;
    
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
    
    int query(int x, int y) { return getSum(y) - getSum(x - 1); }

    vector<int> countSmaller(vector<int>& nums) {
        const int len = nums.size(); 
        tree.resize(n + 1);
        vector<int> res(len);
        for (int i = len - 1; i >= 0; --i) {
            int x = nums[i] + 10001;
            res[i] = getSum(x - 1);
            update(x, 1);
        }
        return res;
    }
};
