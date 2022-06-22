// https://leetcode.com/problems/nth-digit/
#include <iostream>
#include <math.h>

class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        long sum = 0;
        int digit = 1;
        while(sum < n) {
            sum += 9 * digit * pow(10, digit - 1);
            digit++;
        }
        long min = sum - n;
        long mod = min % (digit - 1);
        long div = min / (digit - 1);
        int num = pow(10, digit - 1) - div - 1;
        return (num % (int) pow(10, mod + 1)) / (int) pow(10, mod);
    }
};