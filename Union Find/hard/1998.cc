// https://leetcode.com/problems/gcd-sort-of-an-array/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) parent[pu] = pv;
    }
};

class Solution {
public:
    vector<int> spf;
    
    bool gcdSort(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        sieve(maxNum + 1);
        UnionFind uf(maxNum+1);
        
        for (int x : nums) {
            for (int f : getPrimeFactors(x))
                uf.merge(x, f);
        }

        vector<int> sortedArr(nums);
        sort(sortedArr.begin(), sortedArr.end());
        
        for (int i = 0; i < nums.size(); ++i) {
            if (uf.find(nums[i]) != uf.find(sortedArr[i]))
                return false;
        }
        return true;
    }
    
    void sieve(int n) {
        spf.resize(n);
        for (int i = 2; i < n; ++i) spf[i] = i;
        for (int i = 2; i * i < n; i++) {
            if (spf[i] != i) continue;
            for (int j = i * i; j < n; j += i)
                if (spf[j] > i) spf[j] = i;
        }
    }
    
    vector<int> getPrimeFactors(int n) {
        vector<int> factors;
        while (n > 1) {
            factors.emplace_back(spf[n]);
            n /= spf[n];
        }
        return factors;
    }
};