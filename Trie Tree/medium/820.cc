// https://leetcode.com/problems/short-encoding-of-words/
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

class Trie {
public:
    Trie() : len(0) { memset(next, 0, sizeof(next)); }
    void insert(const string &s) {
        Trie *cur = this;
        for (int i = s.size() - 1; i >= 0; --i) {
            int index = s[i] - 'a';
            if (cur->next[index] == nullptr) 
                cur->next[index] = new Trie;
            cur = cur->next[index];
        }
        cur->len = s.size();
    }
    int getLengthEncoding() {
        int lensum = 0;
        queue<Trie*> q;
        for (int i = 0; i < 26; ++i) {
            if (next[i]) q.push(next[i]);
            while (!q.empty()) {
                const int size = q.size();
                for (int i = 0; i < size; ++i) {
                    Trie *t = q.front(); 
                    q.pop();
                    bool isLeaf = true;
                    for (int j = 0; j < 26; ++j) {
                        if (t->next[j]) { 
                            q.push(t->next[j]);
                            isLeaf = false;
                        }
                    }
                    if (isLeaf) lensum += t->len + 1;
                }
            }
        }
        return lensum;
    }
private:
    Trie *next[26];
    size_t len;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        if (words.size() == 1) return words[0].size() + 1;
        Trie dict;
        for (const string &word : words) dict.insert(word);
        return dict.getLengthEncoding();
    }
};