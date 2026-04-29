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
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;

        while(cur != nullptr) {
            ListNode* nextOfCur = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextOfCur;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        /* STEP 1: Find the middle node of the list using slow pointer, fast pointer technique. */
        ListNode* slow = head;
        ListNode* fast = slow;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        /* 
         * Note: The above while loop repeats exatcly (n / 2) + 1 times. Thus, the next
         * of the slow pointer shows the middle of the linked list. (n is the size of linked list)
         */
        ListNode* mid = slow->next;
        /* Note: The slow pointer is the tail of the result. */
        slow->next = NULL;

        /* STEP 2: Reverse the second half of the linked list. */
        ListNode* revCur = reverse(mid);

        /* STEP 3: Now that we know which nodes need to be replaced, do the update. */
        ListNode* cur = head;
        while(revCur != NULL && cur != NULL) {
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = revCur->next;
        
            cur->next = revCur;
            revCur->next = tmp1;

            cur = tmp1;
            revCur = tmp2;
        }


    }
};
