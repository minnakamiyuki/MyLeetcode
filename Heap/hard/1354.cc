// https://leetcode.com/problems/construct-target-array-with-multiple-sums/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        const int n = target.size();
        if (n == 1) {
            return target[0] == 1;
        }
        ll sum = 0;
        priority_queue<ll> q;
        for (auto &t : target) {
            sum += t;
            q.emplace(t);
        }
        while (q.top() != 1) {
            ll tp = q.top();
            q.pop();
            ll re = sum - tp;
            int scale = max(1, (int)((tp - q.top()) / re));
            ll num = tp - scale * re;
            if (num < 1) 
                return false;
            q.emplace(num);
            sum -= scale * re;
        }
        return true;
    }
};
