// https://leetcode.com/problems/number-of-visible-people-in-a-queue/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        const int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && heights[i] > heights[s.top()]) {
                s.pop();
                ans[i]++;
            }
            ans[i] += !s.empty();
            s.emplace(i);
        }
        return ans;
    }
};