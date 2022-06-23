// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
        auto it = std::upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters[0] : *it;
    }
};