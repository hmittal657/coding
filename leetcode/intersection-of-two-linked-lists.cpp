// https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) return headA;
        if (headA == NULL || headB == NULL) return NULL;
        int m = 0;
        int n = 0;

        ListNode* a = headA;
        while (a) {
            m++;
            a = a->next;
        }

        ListNode* b = headB;
        while (b) {
            n++;
            b = b->next;
        }

        if (m > n) {
            int t = m-n;
            while (t > 0) {
                headA = headA->next;
                t--;
            }
        } else {
            int t = n-m;
            while (t > 0) {
                headB = headB->next;
                t--;
            }
        }

        while (headA) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;

    }
};