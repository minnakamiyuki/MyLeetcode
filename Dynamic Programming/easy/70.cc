// https://leetcode.com/problems/climbing-stairs/
#include <iostream>
using ll = long long;

class Solution {
public:
    int climbStairs(int n) {
        ll f1 = 1, f2 = 2;
        while(n - 1 > 0) {
            ll tmp = f1;
            f1 = f2;
            f2 = tmp + f2;
            n--;
        }
        return f1;
    }
};