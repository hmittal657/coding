// https://leetcode.com/problems/all-possible-full-binary-trees

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
    vector<TreeNode*> allPossibleFBT(int n) {
      if (n%2 == 0) return vector<TreeNode*>(0);

      if (n == 1) {
        TreeNode* t = new TreeNode(0);
        vector<TreeNode*> v;
        v.push_back(t);
        return v;
      }

      vector<TreeNode*> ans;

      for (int i = 1; n-i-1 > 0; i+=2) {
        vector<TreeNode*> v1 = allPossibleFBT(i);
        
        vector<TreeNode*> v2 = allPossibleFBT(n-i-1);
        for (int k = 0; k < v1.size(); k++) {
            for (int l = 0; l < v2.size(); l++) {
                TreeNode* t = new TreeNode(0);
                t->left = v1[k];
                t->right = v2[l];
                ans.push_back(t);
            }
        }
      }

        return ans;
    }
};