// https://leetcode.com/problems/strong-password-checker-ii/submissions/
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        const int n = password.size();
        if (n < 8) return false;
        bool hasBig = false, hasSmall = false, hasDigit = false, hasSpecial = false, hasSame = true;
        unordered_set<char> cnt;
        string special = "!@#$%^&*()-+";
        for (auto c : special) {
            cnt.emplace(c);
        }
        for (int i = 0; i < n; ++i) {
            if (password[i] >= 'A' && password[i] <= 'Z')
                hasBig = true;
            if (password[i] >= 'a' && password[i] <= 'z')
                hasSmall = true;
            if (password[i] >= '0' && password[i] <= '9')
                hasDigit = true;
            if (cnt.count(password[i]))
                hasSpecial = true;
            if (i > 0 && password[i] == password[i - 1])
                hasSame = false;
        }
        if (hasBig && hasSmall && hasDigit && hasSpecial && hasSame)
            return true;
        return false;
    }
};