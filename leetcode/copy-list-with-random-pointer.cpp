// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if (head == NULL) return head;

        unordered_map<Node*, Node*> m;

        Node* new_head = new Node(77);

        Node* cur_new = new_head;

        Node* cur = head;

        while (cur) {
            Node* t = new Node(cur->val);
            m[cur] = t;
            cur_new->next = t;
            cur_new = cur_new->next;
            cur = cur->next;
        }

        cur = head;

        cur_new = new_head->next;

        while (cur) {
            if (cur->random) {
                cur_new->random = m[cur->random];
            }
            cur = cur->next;
            cur_new = cur_new->next;
        }

        return new_head->next;

    }
};