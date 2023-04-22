// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

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

    int fun(TreeNode* root, int dir, int &ans, unordered_map<TreeNode*, unordered_map<int, int>>& m) {

        if (root == NULL) return 0;

        if (m.find(root) != m.end()) {
            if ((m[root]).find(dir) != m[root].end()) {
                return m[root][dir];
            }
        }

        int z = 0;

        if (dir == 0) {
            if (root->right) {
                int a = fun(root->right, 1-dir, ans, m);
                z = a+1;
            } else {
                z = 0;
            }
        } else {
            if (root->left) {
                int b = fun(root->left, 1-dir, ans, m);
                z = b+1;
            } else {
                z = 0;
            }
        }

        ans = max(ans, z);

        if (root->right) {
            int a = 1 + fun(root->right, 1, ans, m);
            ans = max(ans, a);
        }

        if (root->left) {
            int a = 1 + fun(root->left, 0, ans, m);
            ans = max(ans, a);
        }

        if (m.find(root) != m.end()) {
            m[root][dir] = z;
        } else {
            unordered_map<int, int> temp;
            temp[dir] = z;
            m[root] = temp;
        }

        return m[root][dir];

    }

    int longestZigZag(TreeNode* root) {
        unordered_map<TreeNode*, unordered_map<int, int>> m;

        int ans = 0;

        fun(root, 0, ans, m);
        fun(root, 1, ans, m);

        return ans;

    }
};