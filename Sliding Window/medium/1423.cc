// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        const int n = cardPoints.size();
        const int sum = std::accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (k == n) return sum;
        const int len = n - k;
        int cnt = std::accumulate(cardPoints.begin(), cardPoints.begin() + len, 0);
        int res = cnt;        
        for (int i = len; i < n; ++i) {
            cnt += cardPoints[i] - cardPoints[i - len];
            res = std::min(res, cnt);
        }
        return sum - res;
    }
};