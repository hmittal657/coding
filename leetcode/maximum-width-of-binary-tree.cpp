// https://leetcode.com/problems/maximum-width-of-binary-tree/

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

    #define ll unsigned long long

    struct Node {
        TreeNode* r;
        ll pos;
        ll level;
    };

    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        int ans = 1;
        
        queue<Node> q;

        Node x;
        x.r = root;
        x.pos = 0;
        x.level = 0;

        q.push(x);

        while (!q.empty()) {

            Node cur = q.front();
            int curlevel = cur.level;

            vector<Node> v;

            while (!q.empty() && q.front().level == cur.level) {
                v.push_back(q.front());
                q.pop();
            }

            if (v.size() > 1) {
                Node fir = v[0];
                Node las = v[v.size()-1];

                ans = max(ans, (int)(las.pos - fir.pos + 1));
            }

            for (int i =0; i < v.size(); i++) {
                Node x = v[i];
                TreeNode* temp = x.r;
                if (temp->left) {
                    Node k;
                    k.r = temp->left;
                    k.level = curlevel+1;
                    k.pos = (x.pos << 1) + 0;
                    q.push(k);
                }

                if (temp->right) {
                    Node k;
                    k.r = temp->right;
                    k.level = curlevel+1;
                    k.pos = (x.pos << 1) + 1;
                    q.push(k);
                }
            }
        }

        return ans;

    }
};