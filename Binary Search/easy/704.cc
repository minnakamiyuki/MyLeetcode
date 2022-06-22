// https://leetcode.com/problems/binary-search/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};