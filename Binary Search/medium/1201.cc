// https://leetcode.com/problems/ugly-number-iii/
#include <iostream>

class Solution {
public:
    typedef long long ll;
    ll gcd(ll a, ll b) {
        return b ? gcd(b, a % b) : a;
    }
    
    ll lcm(ll a, ll b) {
        return a * b / gcd(a, b);
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        ll ab = lcm(a, b);
        ll bc = lcm(b, c);
        ll ac = lcm(a, c);
        ll abc = lcm(a, bc);
        int l = 0, r = 2 * (int) 1e9;
        while (l < r) {
            ll mid = (l + r*1ll) >> 1;
            ll k = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;
            if (k < n) 
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};