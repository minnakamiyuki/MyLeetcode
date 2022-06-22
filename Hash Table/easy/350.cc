// https://leetcode.com/problems/intersection-of-two-arrays-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto& c : nums1) {
            mp[c]++;
        }
        for (auto& c : nums2) {
            if (mp[c] >= 1) {
                ans.push_back(c);
                mp[c]--;
            }
        }
        return ans;
    }
};