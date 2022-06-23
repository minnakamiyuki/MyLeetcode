// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const int n = spells.size(), m = potions.size();
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for (auto &x : spells) {
            long long cur = (success + x - 1) / x;
            long long y = potions.end() - lower_bound(potions.begin(), potions.end(), cur);
            ans.emplace_back(y);
        }
        return ans;
    }
};