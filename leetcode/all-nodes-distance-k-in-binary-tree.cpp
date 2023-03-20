// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool found = false;

    void travel(TreeNode* root, TreeNode* target, vector<pair<TreeNode*, int>>& cur) {
        if (found) return;

        if (root == target) {
            found = true;
            return;
        }

        if (root->left) {
            cur.push_back({root, 0});
            travel(root->left, target, cur);
            
            if (found) return;
            cur.pop_back();
        }

        if (root->right) {
            cur.push_back({root, 1});
            travel(root->right, target, cur);
            if (found) return;
            cur.pop_back();
        }

    }

    void fun(TreeNode* root, int dist, vector<int>& ans) {
        if (dist < 0) return;
        if (root == NULL) return;
        if (dist == 0) {
            ans.push_back(root->val);
            return;
        }

        if (root->left) {
            fun(root->left, dist-1, ans);
        }

        if (root->right) {
            fun(root->right, dist-1, ans);
        }

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == NULL) return vector<int>(0);
        if (target == NULL) return vector<int>(0);

        vector<pair<TreeNode*, int>> cur;

        found = false;

        travel(root, target, cur);

        vector<int> ans;

        fun(target, k, ans);

        for (int i = cur.size()-1; i >= 0; i--) {
            if (cur.size() - i == k) {
                ans.push_back(cur[i].first->val);
                break;
            } else {
                if (cur[i].second == 0) {
                    fun(cur[i].first->right, k - cur.size() + i - 1, ans);
                } else {
                    fun(cur[i].first->left, k - cur.size() + i - 1, ans);
                }
            }
        }

        return ans;
    }
};