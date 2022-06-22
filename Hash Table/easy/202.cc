// https://leetcode.com/problems/happy-number/
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> hash;
        while (n != 1) {
            hash.insert(n);
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (hash.find(sum) != hash.end()) {
                return false;
            }
            n = sum;
        }
        return true;
    }
};