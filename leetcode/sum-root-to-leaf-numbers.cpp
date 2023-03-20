// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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

    int sum = 0;

    void travel(TreeNode* root, int cur) {
        if (root == NULL) return;
        cur = cur*10 + (root->val);
        if (root->left == NULL && root->right == NULL) {
            sum += cur;
            return;
        }

        travel(root->left, cur);
        travel(root->right, cur);

    }

    int sumNumbers(TreeNode* root) {
        sum = 0;

        travel(root, 0);

        return sum;

    }
};