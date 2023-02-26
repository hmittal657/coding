// https://leetcode.com/problems/find-duplicate-subtrees

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

    vector<TreeNode*> ans;
    unordered_map<int, int> cnt;
    unordered_map<string, int> m;

    int traverse(TreeNode* node) {
        if (node == nullptr) return 0;
        string triplet = to_string(traverse(node->left))
                        + "," + to_string(node->val)
                        + "," + to_string(traverse(node->right));
        if (m.find(triplet) == m.end()) {
            m[triplet] = m.size()+1;
        }
        int id = m[triplet];
        cnt[id]++;
        if (cnt[id] == 2) {
            ans.push_back(node);
        }
        return id;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        while (ans.size() > 0) ans.pop_back();
        cnt.clear();
        m.clear();

        traverse(root);

        return ans;
        
    }
};