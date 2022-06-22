// https://leetcode.com/problems/container-with-most-water/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        const int N = height.size();
        int maxarea = 0, l = 0, r = N - 1;
        while(l < r) {
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
};