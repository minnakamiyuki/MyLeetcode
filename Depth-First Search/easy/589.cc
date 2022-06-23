// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
#include <iostream>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void dfs(Node *root, std::vector<int> &ans) {
        if (root == nullptr) 
            return;
        ans.emplace_back(root->val);
        for (auto &i : root->children) {
            dfs(i, ans);
        }
    }
    
    std::vector<int> preorder(Node* root) {
        std::vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};