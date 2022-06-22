// https://leetcode.com/problems/groups-of-strings/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

template<class T>
class EC {
public:
    unordered_map<T, T> Set;
    unordered_map<T, int> Size;
    int maxSize, group;

    int find(T classA) {
        auto iter = Set.find(classA);
        if (classA != iter->second) {
            iter->second = find(iter->second);
            return iter->second;
        }
        
        return classA;
    }
    
    inline void merge(T classA, T classB) {
        if (Set.find(classB) == Set.end()) {
            return;
        }
        
        classA = find(classA);
        classB = find(classB);
        
        if (classA == classB) {
            return;
        }
        
        Set[classB] = classA;
        
        --group;
        Size[classA] += Size[classB];
        maxSize = max(maxSize, Size[classA]);
    }
    
    void insert(T classA) {
        if (Set.find(classA) == Set.end()) {
            ++group;
            Set[classA] = classA;
        }
        
        ++Size[classA];
        maxSize = max(maxSize, Size[classA]);
    }
};

class Solution {
private: 
    EC<int> ec;

public:
    vector<int> groupStrings(vector<string>& words) {
        for (auto &word : words) {
            int val = 0;
            for (auto &ch : word) {
                val |= (1 << (ch - 'a'));
            }
            
            ec.insert(val);
        }
        
        for (auto &t : ec.Set) {
            for (int i = 0; i < 26; ++i) {
                ec.merge(t.first, t.first ^ (1 << i));
                if (t.first & (1 << i)) {
                    for (int j = 0; j < 26; ++j) {
                        if ((t.first & (1 << j)) == 0)
                            ec.merge(t.first, t.first ^ (1 << i) ^ (1 << j));
                    }
                }
            }
        }
        return { ec.group, ec.maxSize };
    }
};