// https://leetcode.com/problems/symmetric-tree

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

    int EMP = -10000;

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        
        vector<TreeNode*> v;
        if (root->left) {
            v.push_back(root->left);
        }

        if (root->right) {
            v.push_back(root->right);
        }

        while (v.size() > 0) {
            vector<TreeNode*> temp;
            if (v.size() % 2 == 1) return false;
            int l = 0;
            int h = v.size()-1;

            while (l < h) {
                if (v[l] == NULL && v[h] == NULL) {
                    l++;
                    h--;
                } else if (v[l] == NULL || v[h] == NULL) {
                    return false;
                } else {
                    if (v[l]->val != v[h]->val) return false;
                    l++;
                    h--;
                }
            }

            for (int i = 0; i < v.size(); i++) {
                if (v[i] == NULL) continue;
                temp.push_back(v[i]->left);
                temp.push_back(v[i]->right);
            }

            v = temp;
        }

        return true;
    }
};