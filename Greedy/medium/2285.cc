// https://leetcode.com/problems/maximum-total-importance-of-roads/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

class Solution {
public:
    ll maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        ll res = 0;
        const int len = roads.size();
        for (int i = 0; i < len; ++i) {
            int x = roads[i][0];
            int y = roads[i][1];
            degree[x]++;
            degree[y]++;
        }
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(degree[i], i);
        }
        sort(arr.begin(), arr.end());
        for (int i = n - 1; i >= 0; --i) {
            res += (ll) (i + 1) *arr[i].first;
        }
        return res;
    }
};