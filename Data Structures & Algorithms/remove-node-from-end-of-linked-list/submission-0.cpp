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
        ListNode* slow = head;
        ListNode* fast = head->next;
        int cnt = 0;
        int size = 0;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast= fast->next->next;
            cnt++;
        }
        if(fast == NULL){
            size = cnt*2 +1;
        }
        else{
            size = (cnt+1)*2;
        }
        int target = size -n;
        ListNode* cur = head;
        ListNode* prev = NULL;
        for(int i=0; i<target; i++){
            prev = cur;
            cur = cur->next;
        }
        if(cur==head) return head->next;
        prev -> next = cur->next;

        return head;
    }
};
