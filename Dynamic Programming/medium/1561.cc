// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxCoins(std::vector<int>& piles) {
        int sum = 0;
        std::sort(piles.rbegin(), piles.rend());
        for (int i = 0, j = 1; i < piles.size() / 3; ++i, j += 2) {
            sum += piles[j];
        }
        return sum;
    }
};