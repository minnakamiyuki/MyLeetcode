// https://leetcode.com/problems/merge-sorted-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m-- + n-- - 1;
        while(m >= 0 && n >= 0)
            nums1[last--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        while(n >= 0)
            nums1[last--] = nums2[n--];
    }
};