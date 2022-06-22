// https://leetcode.com/problems/jump-game-ii/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        const int len = nums.size();
        if (len == 1) return 0;
        
        int l = -1, r = nums[0] + 0, count = 0;
        for (int i = 0; i < len; ++i) {
            if (i > l) {
                l = r;
                ++count;
            }
            r = max(r, i + nums[i]);
        }
        return count;
    }
};