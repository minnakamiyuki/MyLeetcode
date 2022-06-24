// https://leetcode.com/problems/matrix-block-sum/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        const int m = mat.size(), n = mat[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> res(m, vector<int>(n, 0));
        //求矩形前缀和,s[i + 1][j + 1]表示的是mat[i][j]的矩形前缀和
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) 
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mat[i - 1][j - 1];
        }
        //求res
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int xMin = max(0, i - k), yMin = max(0, j - k);
                int xMax = min(m - 1, i + k), yMax = min(n - 1, j + k);
                res[i][j] = s[xMax + 1][yMax + 1] - s[xMin][yMax + 1] - s[xMax + 1][yMin] + s[xMin][yMin];
            }
        }
        return res;
    }
};
