// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        queue<pair<Node*, int>> q;

        Node* dummy = nullptr;

        q.push({root, 0});

        int highest = -1;

        while (!q.empty()) {
            pair<Node*, int> cur = q.front();
            q.pop();
            Node* c = cur.first;
            int level = cur.second;
            if (level > highest) {
                dummy = c;
                highest = level;
            } else {
                dummy->next = c;
                dummy = c;
            }

            if (c->left) {
                q.push({c->left, level+1});
            }
            if (c->right) {
                q.push({c->right, level+1});
            }

        }
        return root;
    }
};