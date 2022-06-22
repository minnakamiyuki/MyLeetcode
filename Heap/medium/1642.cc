// https://leetcode.com/problems/furthest-building-you-can-reach/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> PQ;
        int sum = 0, cnt = 0;
        for (int i = 1; i < n; ++i) {
            int div = max(0, heights[i] - heights[i - 1]);
            PQ.push(div);
            if (PQ.size() > ladders) {
                sum += PQ.top();
                PQ.pop();
                if (sum > bricks) break;
            }
            cnt = i;
        }
        return cnt;
    }
};