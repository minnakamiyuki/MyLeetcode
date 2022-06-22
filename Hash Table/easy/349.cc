// https://leetcode.com/problems/intersection-of-two-arrays/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size(), n = nums2.size();
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> res;
        for (const auto &a : nums2) {
            if (set.count(a)) {
                set.erase(a);
                res.push_back(a);
            }
        }
        return res;
    }
};