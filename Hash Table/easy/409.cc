// https://leetcode.com/problems/longest-palindrome/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int cnt = 0;
        for (char ch : s) {
            mp[ch]++;
        }
        for (auto num : mp) {
            if (num.second & 1) cnt++;
        }
        if (cnt == 0) return s.size();
        else return s.size() - cnt + 1;
    }
};