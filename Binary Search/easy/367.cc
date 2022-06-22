// https://leetcode.com/problems/valid-perfect-square/
#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1, r = num;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (mid * mid > (long long)num) {
                r = mid - 1;
            } else if (mid *mid < num) {
                l = mid + 1;
            } else return true;
        }
        return false;
    }
};