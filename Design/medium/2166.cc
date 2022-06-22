// https://leetcode.com/problems/design-bitset/
#include <iostream>
#include <vector>
#include <string>

class Bitset {
public:
    std::vector<bool>bits;
    int cnt;
    bool isFlip;
    Bitset(int size) {
        bits.resize(size, false);
        cnt = 0;
        isFlip = false;
    }
    
    void fix(int idx) {
        if (!((bits[idx] + isFlip)&1)){
            cnt++;
            bits[idx] = !bits[idx];  
        }
    }
    
    void unfix(int idx) {
        if ((bits[idx] + isFlip)&1) {
            cnt--;
            bits[idx] = !bits[idx];  
        } 
    }
    
    void flip() {
        cnt = bits.size()-cnt;
        isFlip = !isFlip;
    }
    
    bool all() {
        return cnt == bits.size(); 
    }
    
    bool one() {
        return cnt >= 1;
    }
    
    int count() {
        return cnt; 
    }
    
    std::string toString() {
        std::string ans;
        for(auto bit : bits)
            ans.push_back((bit + isFlip) % 2 ? '1' : '0')  ;   
        return ans;
    }
};
