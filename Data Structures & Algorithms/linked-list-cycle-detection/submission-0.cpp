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
    bool hasCycle(ListNode* head) {
        ListNode* dummy = new ListNode();

        ListNode* cur = head;
        while(cur!=NULL){
            if(cur->next == dummy) return true;
            ListNode* temp = cur->next;
            cur->next = dummy;
            cur = temp;
        }
        return false;
    }
};
