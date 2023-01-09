// https://leetcode.com/problems/balanced-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int height(TreeNode* root, unordered_map<TreeNode*, int>& m) {
        if (root == NULL) return 0;
        if (m.find(root) != m.end()) return m[root];
        int l = height(root->left, m);
        int h = height(root->right, m);

        m[root] = 1 + max(l, h);
        return m[root];
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        unordered_map<TreeNode*, int> m;

        int l = height(root->left, m);
        int h = height(root->right, m);

        if (abs(l-h) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);

    }
};