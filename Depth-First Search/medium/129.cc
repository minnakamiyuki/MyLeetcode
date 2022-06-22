// https://leetcode.com/problems/sum-root-to-leaf-numbers/
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res = 0;
    
    void dfs(TreeNode *root, int number) {
        number = number * 10 + root->val;
        if (!root->left && !root->right) res += number;
        if (root->left) dfs(root->left, number);
        if (root->right) dfs(root->right, number);
    }
    
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};