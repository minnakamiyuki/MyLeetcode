// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> charIndex(256, -1);
        int longest = 0, m = 0;

        for (int i = 0; i < s.length(); i++) {
            m = std::max(charIndex[s[i]] + 1, m);
            charIndex[s[i]] = i;
            longest = std::max(longest, i - m + 1);
        }

        return longest;
    }
};