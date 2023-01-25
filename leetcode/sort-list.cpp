// https://leetcode.com/problems/sort-list/

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

    
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        int n = 0;
        ListNode* cur = head;
        ListNode* doubleSpeed = cur;

        while (cur) {
            if (doubleSpeed == NULL || doubleSpeed->next == NULL) {
                break;
            }
            cur = cur->next;
            doubleSpeed = doubleSpeed->next;
            doubleSpeed = doubleSpeed->next;
        }

        ListNode* head2 = cur;
        ListNode* temp = head;
        while (temp->next != head2) {
            temp = temp->next;
        }
        temp->next = NULL;

        head = sortList(head);
        head2 = sortList(head2);

        ListNode* dummyHead = new ListNode(0);
        ListNode* dummyCur = dummyHead;

        while (head && head2) {
            if ((head->val) < (head2->val)) {
                ListNode* temp = head->next;
                dummyCur->next = head;
                dummyCur = dummyCur->next;
                dummyCur->next = nullptr;
                head = temp;
            } else {
                ListNode* temp = head2->next;
                dummyCur->next = head2;
                dummyCur = dummyCur->next;
                dummyCur->next = nullptr;
                head2 = temp;
            }
        }

        while (head) {
            ListNode* temp = head->next;
            dummyCur->next = head;
            dummyCur = dummyCur->next;
            dummyCur->next = nullptr;
            head = temp;
        }

        while (head2) {
            ListNode* temp = head2->next;
            dummyCur->next = head2;
            dummyCur = dummyCur->next;
            dummyCur->next = nullptr;
            head2 = temp;
        }

        return dummyHead->next;

    }
};