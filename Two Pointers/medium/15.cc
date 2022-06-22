// https://leetcode.com/problems/3sum/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        const int len = nums.size();
        if (len < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len && nums[i] <= 0; i++) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = len - 1;
            int sum = 0 - nums[i];
            while(left < right){
                if (nums[left] + nums[right] > sum) {
                    right--;
                }
                else if (nums[left] + nums[right] < sum) {
                    left++;
                }
                else {
                    vector<int> ians = { nums[i], nums[left], nums[right] };
                    ans.push_back(ians);
                    left++;
                    right--;
                    while (left < right && nums[left - 1] == nums[left])
                        left++;
                    while (left < right && nums[right + 1] == nums[right])
                        right--;
                }
            }
        }
        return ans;
    }
};