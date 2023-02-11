// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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

    
    int prev = -1;
    int ans = INT_MAX;

    void help(TreeNode* r) {
        if (r == NULL) return;
        
        help(r->left);

        if (prev == -1) {
            prev = r->val;
        } else {
            ans = min(ans, abs(r->val - prev));
            prev = (r->val);
        }

        help(r->right);
    }


    int minDiffInBST(TreeNode* root) {
        ans = INT_MAX;
        prev = -1;
        help(root);
        return ans;
    }
};