// https://leetcode.com/problems/pascals-triangle/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if(numRows >= 1)
            res[0].push_back(1);
        if(numRows == 1) return res;
        if(numRows >= 2)
            res[1].push_back(1);
            res[1].push_back(1);
        for(int i = 2; i < numRows; i++) {
            int n = i + 1;
            for(int j = 0; j < n; j++) {
                if(j == 0 || j == n - 1) {
                    res[i].push_back(1);
                } else {
                    res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
            }
        }
        return res;
    }
};