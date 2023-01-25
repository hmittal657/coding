// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* cur = head;

        ListNode* dummyHead = new ListNode(0);

        ListNode* dummyCur = dummyHead;

        while (cur) {
            ListNode* a = cur;
            if (cur->next) {
                ListNode* b = cur->next;
                ListNode* tempNext = b->next;
                dummyCur->next = b;
                dummyCur = dummyCur->next;
                dummyCur->next = a;
                dummyCur = a;
                dummyCur->next = NULL;
                cur = tempNext;
            } else {
                dummyCur->next = cur;
                break;
            }
        }

        return dummyHead->next;

    }
};