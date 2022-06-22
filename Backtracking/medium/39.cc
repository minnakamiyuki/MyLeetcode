// https://leetcode.com/problems/combination-sum/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void getCombination(vector<int>& nums, int sum, int start, vector<vector<int>>& res, vector<int>& temp){
        if(sum != 0 && sum < nums[start]) return;
        if(sum == 0){
            res.push_back(temp);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            temp.push_back(nums[i]);
            getCombination(nums, sum - nums[i], i, res, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        getCombination(candidates, target, 0, res, temp);
        
        return res;
    }
};