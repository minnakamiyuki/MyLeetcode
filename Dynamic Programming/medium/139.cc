// https://leetcode.com/problems/word-break/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                string sij = s.substr(j, i - j);
                if (wordSet.find(sij) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};