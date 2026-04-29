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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        } else if(list2 == nullptr) {
            return list1;
        }
        
        ListNode* newHead = nullptr;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* newTail = nullptr;

        if(list1->val <= list2->val) {
            newHead = list1;
            cur1 = list1->next;
        } else {
            newHead = list2;
            cur2 = list2->next;
        }

        newTail = newHead;
        while(cur1 != nullptr && cur2 != nullptr) {
            if(cur1->val <= cur2->val) {
                newTail->next = cur1;
                cur1 = cur1->next;
            } else {
                newTail->next = cur2;
                cur2 = cur2->next;
            }
            newTail = newTail->next;
        }

        if(cur1 != nullptr) {
            newTail->next = cur1;
        } else if(cur2 != nullptr) {
            newTail->next = cur2;
        }

        return newHead;
    }
};
