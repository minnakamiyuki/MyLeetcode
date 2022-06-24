// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/
#include <iostream>
#include <vector>

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        std::vector<bool> a(15);
        int cur = 1, s = k;
        while (s % 10 != num % 10) {
            ++cur;
            s += k;
            if (a[s % 10]) return -1;
            a[s % 10] = true;
        }
        if (num < s) return -1;
        else return cur;
    }
};