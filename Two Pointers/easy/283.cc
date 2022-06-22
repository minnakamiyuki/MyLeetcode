// https://leetcode.com/problems/move-zeroes/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int n = nums.size();
        int k = 0;
        for (auto &x : nums) 
            if (x) nums[k++] = x;
        while (k < n) nums[k++] = 0;
    }
};