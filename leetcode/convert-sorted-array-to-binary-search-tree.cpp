// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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

    TreeNode* convert(vector<int>& nums, int i, int j) {
        if (i > j || i < 0 || j >= nums.size()) return NULL;
        if (i == j) {
            TreeNode* a = new TreeNode();
            a->val = nums[i];
            return a;
        }

        int m = (i+j)/2;
        TreeNode* a = new TreeNode();
        a->val = nums[m];

        a->left = convert(nums, i, m-1);
        a->right = convert(nums, m+1, j);

        return a;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n = nums.size();

        return convert(nums, 0, n-1);

    }
};