// https://leetcode.com/problems/find-bottom-left-tree-value

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
    int findBottomLeftValue(TreeNode* root) {
        int maxilevel = 0;
        queue<pair<TreeNode*, int>> q;
        int ans = root->val;
        q.push({root, 0});

        while (!q.empty()) {
            pair<TreeNode*, int> cur = q.front();
            if (cur.second >= maxilevel) {
                ans = cur.first->val;
                maxilevel = cur.second;
            }
            q.pop();

            if (cur.first->right) {
                q.push({cur.first->right, cur.second+1});
            }

            if (cur.first->left) {
                q.push({cur.first->left, cur.second+1});
            }

        }

        return ans;
    }
};