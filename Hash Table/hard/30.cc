// https://leetcode.com/problems/substring-with-concatenation-of-all-words/submissions/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int a = s.size(), b = words.size(), c = words[0].size();
        vector<int> res;
        
        if (!a || !b) return res;

        unordered_map<string, int> mp1;
        for (auto &word : words) {
            mp1[word]++; // 记录单词及出现次数
        }
        
        for (int i = 0; i <= a - b * c; ++i) {
            unordered_map<string, int> mp2;
            int j;
            for (j = 0; j < b; ++j) {
                string t = s.substr(i + j * c, c);
                if (mp1.find(t) == mp1.end()) break; // 未找到
                else ++mp2[t];
                if (mp2[t] > mp1[t]) break; // 出现重复时退出循环
            }
            if (j == b) res.emplace_back(i); // j = b则说明满足条件
        }
        return res;
    }
};