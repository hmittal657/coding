// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curDummy = dummyHead;
        ListNode* cur = head;
        while (cur) {
            ListNode* tempNext = cur->next;
            if (cur->val == val) {
                
            } else {
                curDummy->next = cur;
                curDummy = cur;
                curDummy->next = NULL;
            }
            cur = tempNext;
        }
        return dummyHead->next;
    }
};