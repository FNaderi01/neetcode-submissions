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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 1;
        ListNode* cur = head;

        while(i < n) {
            cur = cur->next;
            i++;
        }

        ListNode* target = head;
        ListNode* prev = NULL;

        while(cur->next != NULL) {
            cur = cur->next;
            prev = target;
            target = target->next;
        }

        if(prev == NULL) {
            return head->next;
        }

        prev->next = target->next;
        return head;
    }
};
