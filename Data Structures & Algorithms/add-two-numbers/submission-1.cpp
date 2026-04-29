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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* resTail = NULL;
        ListNode* resHead = NULL;

        while(cur1 != NULL && cur2 != NULL) {
            int resVal = cur1->val + cur2->val + carry;
            if(resVal >= 10) {
                carry = 1;
                resVal = resVal - 10;
            } else {
                carry = 0;
            }

            ListNode* newNode = new ListNode(resVal);
            if(resTail == NULL) {
                resTail = newNode;
                resHead = newNode;
            } else {
                resTail->next = newNode;
                resTail = newNode;
            }

            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        if(cur1 != NULL) {
            while(cur1 != NULL) {
                int resVal = cur1->val + carry;
                if(resVal >= 10) {
                    carry = 1;
                    resVal = resVal - 10;
                } else {
                    carry = 0;
                }
                ListNode* newNode = new ListNode(resVal);
                resTail->next = newNode;
                resTail = newNode;
                cur1 = cur1->next;
            }
        } else if(cur2 != NULL) {
            while(cur2 != NULL) {
                int resVal = cur2->val + carry;
                if(resVal >= 10) {
                    carry = 1;
                    resVal = resVal - 10;
                } else {
                    carry = 0;
                }
                ListNode* newNode = new ListNode(resVal);
                resTail->next = newNode;
                resTail = newNode;
                cur2 = cur2->next;
            }
        }
        
        if(carry == 1) {
            resTail->next = new ListNode(1, NULL);
        }

        return resHead;
    }
};
