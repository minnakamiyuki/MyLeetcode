// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public: 
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;
    
        for (int i = 0;; ++i) {
            auto it = imap.find(target - nums[i]);
        
            if (it != imap.end()) 
                return vector<int> {i, it->second};
            
            imap[nums[i]] = i;
        }
    }
};
