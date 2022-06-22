// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        const int n = rocks.size();
        int ans = 0;
        vector<int> div(n, 0);
        for (int i = 0; i < n; ++i) {
            div[i] = capacity[i] - rocks[i];
        }
        sort(div.begin(), div.end());
        for (auto &d : div) {
            if (d <= additionalRocks) {
                additionalRocks -= d;
                ans++;
            }
        }
        return ans;
    }
};