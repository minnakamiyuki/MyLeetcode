// https://leetcode.com/problems/match-substring-after-replacement/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Fast Fourier Transform

class Solution {
    int table[256][256]{};
    int sn = 0;
public:
    bool z_function(string& s) {
        int n = (int) s.length();
        vector<int> z(n);
        auto ok = [&](char x,char y){
            return x == y || table[x][y];
        };
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = std::min (r - i + 1, z[i - l]);
            while (i + z[i] < n && ok(s[z[i]], s[i + z[i]]))
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
            if (z[i] == sn) return true;
        }
        return false;
    }

    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        std::string p = sub + "#" + s;
        sn = sub.size();
        for (const auto& m: mappings) {
            table[m[0]][m[1]] = 1;
        }
        return z_function(p);
    }
};
