// https://leetcode.com/problems/trapping-rain-water/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0) return 0;
        vector<int> lm(len), rm(len);
        lm[0] = height[0], rm[len - 1] = height[len - 1];
        for (int i = 1; i < len; ++i) {
            lm[i] = max(lm[i - 1], height[i]);
        }
        
        for (int j = len - 2; j >= 0; --j) {
            rm[j] = max(rm[j + 1], height[j]);
        }
        
        int sum = 0;
        for (int i = 1; i < len - 1; ++i) {
            sum += min(lm[i], rm[i]) - height[i];
        }
        return sum;
    }
};