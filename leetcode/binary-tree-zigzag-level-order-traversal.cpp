// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        int maxlevel = -1;

        while (!q.empty()) {
            pair<TreeNode*, int> cur = q.front();
            q.pop();

            int v = cur.first->val;
            int level = cur.second;

            if (level > maxlevel) {
                maxlevel = level;
                vector<int> t;
                t.push_back(v);
                ans.push_back(t);
            } else {
                ans[ans.size()-1].push_back(v);
            }


            if (cur.first->left) {
                q.push({cur.first->left, level+1});
            }
        
            if (cur.first->right) {
                q.push({cur.first->right, level+1});
            }
            
        }

        for (int i = 1; i < ans.size(); i+=2) {
            int l = 0;
            int h = ans[i].size()-1;
            while (l < h) {
                swap(ans[i][l], ans[i][h]);
                l++;
                h--;
            }
        }

        return ans;

    }
};