// https://leetcode.com/problems/reverse-nodes-in-k-group

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

    ListNode* rev(ListNode* cur_kh, ListNode* cur_ke) {

        ListNode* cur_new = NULL;
        while (true) {
            ListNode* tempNext = cur_kh->next;
            cur_kh->next = cur_new;
            cur_new = cur_kh;
            if (cur_new == cur_ke) {
                return cur_new;
            }
            cur_kh = tempNext;
        }

        return cur_new;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        if (k == 1) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* latest = dummy;

        int index = 0;

        ListNode* cur_kh;
        ListNode* cur_ke;

        ListNode* cur = head;

        while (cur) {
            ListNode* tempnext = cur->next;
            index++;
            if (index == 1) {
                cur_kh = cur;
            } else if (index == k) {
                cur_ke = cur;
                ListNode* newHead = rev(cur_kh, cur_ke);

                latest->next = newHead;

                while (index > 0) {
                    latest = latest->next;
                    index--;
                }
            }

            cur = tempnext;
        }

        if (index > 0) {
            latest->next = cur_kh;
        }

        return dummy->next;

    }
};