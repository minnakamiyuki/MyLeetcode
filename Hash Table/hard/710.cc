// https://leetcode.com/problems/random-pick-with-blacklist/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int whiteLen; 
    unordered_map<int, int> mp;
    Solution(int n, vector<int>& blacklist) {
        const int m = blacklist.size();
        whiteLen = n - m;
        // whiteLen是白名单的长度
        unordered_set<int> wl;
        for (int i = whiteLen; i < n; ++i) {
            wl.insert(i); // 将whiteLen范围外的所有数加入set
        }
        for (auto bl : blacklist) {
            wl.erase(bl); // 去除set中的黑名单数，留下白名单
        }
        unordered_set<int>::iterator iter = wl.begin();
        for (auto bl : blacklist) {
            if (bl < whiteLen)
                // 将范围内的黑名单数->范围外的白名单数
                mp[bl] = *iter++; 
        }
    }
    
    int pick() {
        int ran = random() % whiteLen;
        // 检查这个数是否是范围内的黑名单数
        return mp.count(ran) == 0 ? ran : mp[ran];
    }
};