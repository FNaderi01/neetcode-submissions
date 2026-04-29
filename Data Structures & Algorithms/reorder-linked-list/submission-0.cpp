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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;

        while(cur !=NULL ){
            ListNode* t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        cur = prev;
        // while(cur!=NULL){
        //     cout<<cur->val<<",";
        //     cur = cur->next;
        // }

        return prev;

    }
    void reorderList(ListNode* head) {
        int cnt =0;
        ListNode* cur = head;
        while(cur!=NULL){
            cnt++;
            cur = cur->next;
        }
        cur = head;
        for(int i =1; i<=(cnt/2); i++){
            cur = cur->next;
        }
        ListNode* mid = reverse(cur);
        cur = head;
        while(mid->next!=NULL){
            ListNode* t = cur->next;
            ListNode* p = mid->next;
            cur->next = mid;
            mid->next = t;
            cur = t;
            mid = p;
        }
    }
};
