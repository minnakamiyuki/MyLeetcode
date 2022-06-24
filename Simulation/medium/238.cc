// https://leetcode.com/problems/product-of-array-except-self/
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        const int n = nums.size();
        int fromBegin = 1;
        int fromLast = 1;
        std::vector<int> res(n, 1);
        
        for (int i = 0; i < n; i++) {
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n-1-i] *= fromLast;
            fromLast *= nums[n-1-i];
        }
        return res;
    }
};