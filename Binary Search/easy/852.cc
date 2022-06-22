// https://leetcode.com/problems/peak-index-in-a-mountain-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        const int n = arr.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (arr[mid] < arr[mid + 1])
                l = mid + 1;
            else if (arr[mid] < arr[mid - 1])
                r = mid - 1;
            else return mid;
        }
        return l;
    }
};