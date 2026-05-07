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
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        if(a == NULL) {
            return b;
        }

        if(b == NULL) {
            return a;
        }

        ListNode* dummy = new ListNode();
        ListNode* resTail = dummy;

        ListNode* curA = a;
        ListNode* curB = b;

        while(curA != NULL && curB != NULL) {
            if(curA->val <= curB->val) {
                resTail->next = curA;
                resTail = resTail->next;
                curA = curA->next;
                
            } else {
                resTail->next = curB;
                resTail = resTail->next;
                curB = curB->next;
            }
        }
        if(curA != NULL) {
            resTail->next = curA;
        }
        if(curB != NULL) {
            resTail->next = curB;
        }

        return dummy->next;
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int start, int end) {
        if(start > end) {
            return NULL;
        }

        if(start == end) {
            return lists[start];
        }

        int mid = (start + end) / 2;

        ListNode* left = mergeSort(lists, start, mid);
        ListNode* right = mergeSort(lists, mid + 1, end);

        return mergeTwo(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        if(lists.size() == 1) {
            return lists[0];
        }

        return mergeSort(lists, 0, lists.size() - 1);

    }
};
