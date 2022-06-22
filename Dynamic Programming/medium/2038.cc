// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
#include <iostream>
#include <string>

class Solution {
public:
    bool winnerOfGame(std::string colors) {
        const int n = colors.size();
        int cnt = 0;
        if (n <= 2) return false;
        
        for (int i = 2; i < n; ++i) {
            if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i - 2] == 'A')
                cnt++;
            if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i - 2] == 'B')
                cnt--;
        }
        return cnt > 0;
    }
};