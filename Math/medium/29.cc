// https://leetcode.com/problems/divide-two-integers/
#include <iostream>
#include <limits.h>

class Solution {
public:
    int divide(long dividend, long divisor) {
        if ((dividend == INT_MIN && divisor == -1) || (dividend == INT_MAX && divisor ==1 )) 
            return INT_MAX;
        if (!dividend) return 0;
        int flag = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (dividend < 0) 
            dividend = -dividend;
        if (divisor < 0)
            divisor = -divisor;
        long res = 0;
        while (dividend >= divisor) {
            long ans = 1, tmp = divisor;
            while (dividend >= (tmp << 1)) {
                ans <<= 1;
                tmp <<= 1;
            }
            res += ans;
            dividend -= tmp;
        }
        return flag > 0 ? res : -res;
    }
};