// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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

    int ans = 0;

    void dfs(TreeNode* root, int maxSoFar) {
        if (root == NULL) return;
        if (root->val >= maxSoFar) {
            ans++;
        }

        dfs(root->left, max(maxSoFar, (root->val)));
        dfs(root->right, max(maxSoFar, (root->val)));

    }

    int goodNodes(TreeNode* root) {
        ans= 0;

        dfs(root, -100000);

        return ans;
    }
};