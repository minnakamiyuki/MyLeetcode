// https://leetcode.com/problems/duplicate-zeros/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        const int n = arr.size();
        int pos = 0, i = 0;
        for (; pos < n; ++i) {
            pos += arr[i] ? 1 : 2;
        }
        if (pos > n) {
            arr[pos = n - 1] = 0;
            --i;
        }
        --i;
        for (; pos; --i) {
            if (!(arr[--pos] = arr[i])) {
                arr[--pos] = arr[i];
            }
        }
    }
};