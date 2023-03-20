// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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
    bool isCompleteTree(TreeNode* root) {
        
        vector<TreeNode*> v;

        v.push_back(root);

        while (true) {
            vector<TreeNode*> temp;

            
            bool nullfound = false;
            for (int i =0; i < v.size(); i++) {
                if (nullfound) {
                    if (v[i]) return false;
                } else {
                    if (v[i] == NULL) {
                        nullfound = true;
                    }
                }
            }

            bool islast = true;

            for (int i = 0; i < v.size(); i++) {
                if (!v[i]) {
                    temp.push_back(NULL);
                    temp.push_back(NULL);
                } else {
                    if (v[i]->left || v[i]->right) {
                        islast = false;
                    }
                    temp.push_back(v[i]->left);
                    temp.push_back(v[i]->right);
                }
            }

            if (nullfound && !islast) return false;

            if (islast) return true;

            v = temp;
        }

    }
};