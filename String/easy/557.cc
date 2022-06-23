// https://leetcode.com/problems/reverse-words-in-a-string-iii/
#include <iostream>
#include <algorithm>
#include <string>

class Solution {
public:
    std::string reverseWords(std::string s) {
        const int n = s.size();
        int j = 0;
        if (s.empty()) return s;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' '){
                std::reverse(s.begin() + j, s.begin() + i);
                j = i + 1; 
            } else if (i == n - 1) {
                std::reverse(s.begin() + j, s.end());
            }
        }
        return s;
    }
};