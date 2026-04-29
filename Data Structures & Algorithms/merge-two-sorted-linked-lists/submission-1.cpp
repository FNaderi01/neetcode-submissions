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
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        if (list1->val <= list2->val) {
            head = list1;
            cur1 = list1->next;
        } else {
            head = list2;
            cur2 = list2->next;
        }

        cur = head;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val <= cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
            } else {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        if (cur1 != nullptr) {
            cur->next = cur1;
        } else {
            cur->next = cur2;
        }
        return head;
    }
};
