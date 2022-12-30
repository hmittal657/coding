// https://leetcode.com/problems/partition-list

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
    ListNode* partition(ListNode* head, int x) {
        
        if (head == NULL) return NULL;

        ListNode* less = NULL;
        ListNode* more = NULL;

        ListNode* lessHead = less;
        ListNode* moreHead = more;

        ListNode* cur = head;

        while (cur) {
            ListNode* tempNext = cur->next;
            if ((cur->val) < x) {
                if (less == NULL) {
                    less = cur;
                    lessHead = less;
                    less->next = NULL;
                } else {
                    less->next = cur;
                    less = cur;
                    less->next = NULL;
                }
            } else {
                if (more == NULL) {
                    more = cur;
                    moreHead = more;
                    more->next = NULL;
                } else {
                    more->next = cur;
                    more = cur;
                    more->next = NULL;
                }
            }

            cur = tempNext;
        }

        if (lessHead == NULL && moreHead == NULL) {
            return NULL;
        }
        if (lessHead == NULL) {
            return moreHead;
        }
        if (moreHead == NULL) {
            return lessHead;
        }

        less->next = moreHead;

        return lessHead;

    }
};