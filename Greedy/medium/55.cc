// https://leetcode.com/problems/jump-game/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), i = 0;
        for (int reach = 0; i < n && i <= reach; ++i) {
            reach = max(i + nums[i], reach);
        }
        return i == n;
    }
};