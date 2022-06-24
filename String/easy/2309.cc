// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string greatestLetter(std::string s) {
        std::vector<bool> a(30, false), b(30, false);
        for (auto c : s) {
            if (c >= 'a' && c <= 'z') a[c - 'a'] = true;
            if (c >= 'A' && c <= 'Z') b[c - 'A'] = true;
        }
        int ans = -1;
        for (int i = 0; i < 26; ++i) {
            if (a[i] && b[i]) ans = i;
        }
        std::string res;
        if (ans != -1) res += (char) (ans + 'A');
        return res;
    }
};