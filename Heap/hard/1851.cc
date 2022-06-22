// https://leetcode.com/problems/minimum-interval-to-include-each-query/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int n = queries.size(), m = intervals.size();
        vector<P> queues;
        for (int i = 0; i < n; ++i) {
            queues.emplace_back(queries[i], i);
        }
        sort(queues.begin(), queues.end());
        sort(intervals.begin(), intervals.end());
        
        priority_queue<P> q;
        vector<int> ret(n, -1);
        int j = 0;
        for (auto queue : queues) {
            while (j < m && intervals[j][0] <= queue.first) {
                int len = intervals[j][1] - intervals[j][0] + 1;
                q.push(P(-len, intervals[j][1]));
                j++;
            }
            
            while (!q.empty()) {
                if (q.top().second >= queue.first) {
                    ret[queue.second] = -q.top().first;
                    break;
                }
                q.pop();
            }
        }
        return ret;
    }
};