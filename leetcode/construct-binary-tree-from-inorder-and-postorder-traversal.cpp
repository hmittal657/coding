// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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

    TreeNode* build(vector<int>& in, vector<int>& post, int i, int j, int x, int y,
        unordered_map<int, int>& m) {
        
        if (i > j || x > y) return NULL;

        if (x == y) {
            TreeNode* root = new TreeNode();
            root->val = in[x];
            return root;
        }

        int piv = m[post[j]];

        TreeNode* root = new TreeNode();

        root->val = post[j];

        root->left = build(in, post, i , piv - 1 - x + i , x, piv-1, m);
        root->right = build(in, post, j - y + piv , j-1 , piv+1, y, m);

        return root;

    }

    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {

        int n = in.size();
        unordered_map<int, int> m;
        for (int i = 0; i < in.size(); i++) {
            m[in[i]] = i;
        }

        return build(in, post, 0, n-1, 0, n-1, m);

    }
};