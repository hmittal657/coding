// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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

    ListNode* rev(ListNode* r) {
        
        ListNode* prev = nullptr;        

        while (r) {
            ListNode* temp = r->next;
            r->next = prev;
            prev = r;
            r = temp;
        }

        return prev;

    }

    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* cur = head;

        while (cur) {
            n++;
            cur = cur->next;
        }


        ListNode* mid;

        int i = 0; 

        cur = head;

        while (cur) {
            i++;
            if (i == (n/2)) break;
            cur = cur->next;
        }

        ListNode* sec = cur->next;
        cur->next = nullptr;

        mid = rev(sec);

        cur = head;
        ListNode* cur2 = mid;
        int maxsum = (head->val) + (mid->val);
        while (cur && cur2) {
            
            maxsum = max(maxsum, (cur->val) + (cur2->val));
            
            cur = cur->next;
            cur2 = cur2->next;
        }

        return maxsum;


    }
};