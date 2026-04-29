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
    ListNode* reverseList(ListNode* head) {
        ListNode *newNext = nullptr;
        ListNode *cur = head;
        ListNode* oldNext;
        while(cur != nullptr) {
            oldNext = cur->next;
            cur->next = newNext;
            newNext = cur;
            cur = oldNext;
        }

        return newNext;
    }
};
