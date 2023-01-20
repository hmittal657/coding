// https://leetcode.com/problems/palindrome-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* rev(ListNode* head) {
        if (head == NULL) return head;
        if (head->next == NULL) return head;

        ListNode* dummyHead = NULL;
        ListNode* prev = NULL;

        ListNode* cur = head;

        while (cur) {
            ListNode* tempNext = cur->next;
            dummyHead = cur;
            dummyHead->next = prev;
            prev = dummyHead;
            cur = tempNext;
        }

        return dummyHead;
    }

    bool comp(ListNode* a, ListNode* b) {
        while (a != NULL && b != NULL) {
            if ((a->val) != (b->val)) return false;
            a = (a->next);
            b = (b->next);
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || (head->next) == NULL) return true;
        ListNode* cur = head;
        

        int n = 0;

        while (cur) {
            n++;
            cur = cur->next;
        }

        if (n%2 == 0) {
            int k = (n/2);

            cur = head;
            int ind = -1;
            ListNode* target;
            while (cur) {
                ind++;
                cout << ind << endl;
                if (ind == k) {
                    target = rev(cur);
                    cur->next = NULL;
                    break;
                }
                cur = cur->next;
            }

            return comp(head, target);
        } else {
            int k = (n/2);

            cur = head;
            int ind = -1;
            ListNode* target;
            while (cur) {
                ind++;
                cout << ind << endl;
                if (ind == k) {
                    target = rev(cur);
                    cur->next = NULL;
                    break;
                }
                cur = cur->next;
            }

            return comp(head, target);
        }

        return false;

    }
};