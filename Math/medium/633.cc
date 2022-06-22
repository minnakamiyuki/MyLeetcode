// https://leetcode.com/problems/sum-of-square-numbers/
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long i = 0; i * i <= c; i++) {
            double x = sqrt(c - i * i);
            if (x == (int) x)
                return true;
        }
        return false;
    }
};