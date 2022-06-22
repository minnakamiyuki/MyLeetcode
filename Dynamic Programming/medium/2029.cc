// https://leetcode.com/problems/stone-game-ix/submissions/
#include <iostream>
#include <vector>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int n = 0, m = 0, k = 0;
        for (int val : stones) {
            if (val % 3 == 0) {
                ++n;
            } else if (val % 3 == 1) {
                ++m;
            } else {
                ++k;
            }
        }
        if (!(n & 1)) {
            return m >= 1 && k >= 1;
        }
        return std::abs(m - k) > 2;
    }
};