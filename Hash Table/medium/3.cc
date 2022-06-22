// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int N = s.length();
        int res = 0, m = 0;
        if(N < 2) return N;
        unordered_map<char, int> mp;
        for(int i = 0; i < N; ++i) {
            m = max(mp[s[i]] + 1, m);
            mp[s[i]] = i;
            res = max(res, i - m + 1);
        }
        return res;
    }
};