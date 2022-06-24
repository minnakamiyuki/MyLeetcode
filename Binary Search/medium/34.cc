// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int i = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int j = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (i < nums.size() && nums[i] == target) 
            return {i, j - 1};
        return {-1, -1};
    }
};