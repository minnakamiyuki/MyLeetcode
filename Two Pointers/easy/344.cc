// https://leetcode.com/problems/reverse-string/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        const int n = s.size();
        for (int l = 0, r = n - 1; l < r; ++l, --r) {
            swap(s[l], s[r]);
        }
    }
};