// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        const int n = nums.size();
        int pos = 0, neg = 0, len = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                pos++;
                neg = neg > 0 ? neg + 1 : neg;
            }
            else if (nums[i] < 0) {
                int po = pos;
                pos = neg > 0 ? neg + 1 : neg;
                neg = po + 1;
            }
            else {
                pos = neg = 0;
            }
            len = max(len, pos);
        }
        return len;
    }
};