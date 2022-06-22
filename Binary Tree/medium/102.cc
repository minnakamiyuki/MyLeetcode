// https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeNode *front = q.front();
                q.pop();
                tmp.emplace_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};