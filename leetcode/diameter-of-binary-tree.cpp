// https://leetcode.com/problems/diameter-of-binary-tree

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

    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        
        int lefty = 0;
        int righty = 0;

        if (root->left) {
            lefty = helper(root->left) + 1;
        }
        if (root->right) {
            righty = helper(root->right) + 1;
        }
        int temp = lefty + righty;
        ans = max(ans, temp);
        int z =  max(lefty, righty);
        return z;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        ans = 0;
        int temp = helper(root);
        ans = max(ans, temp);
        return ans;
    }
};