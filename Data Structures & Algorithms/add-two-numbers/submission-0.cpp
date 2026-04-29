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
        ListNode* prev;
        ListNode* cur;
        prev = NULL;
        cur = head;
        while(cur != NULL){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }
    pair<ListNode*, int> addTwoNodes(ListNode* n1, ListNode* n2, int carry){
        if(n1==NULL && n2==NULL) {
            if(carry == 0) return {NULL, 0};
            return {new ListNode(carry),0};
        }
        if(n1==NULL){
            if(carry ==0) return {n2, 0};
            else return addTwoNodes(n2, new ListNode(carry),0);
        }
        if(n2==NULL){
            if(carry ==0)
                return {n1, 0};
            else return addTwoNodes(n1, new ListNode(carry),0);
        } 

        int res = n1->val + n2->val + carry;
        ListNode* ret;
        if(res<10){
            ret = new ListNode(res);
            auto a = addTwoNodes(n1->next, n2->next, 0);
            ret->next = a.first;
            return {ret, a.second}; 
        }
        else {
           ret = new ListNode(res%10);
            auto a = addTwoNodes(n1->next, n2->next, res/10);
            ret->next = a.first;
            return {ret, a.second};  
        }
        return {NULL, 0};
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto res = addTwoNodes(l1, l2, 0);
        if(res.second == 0) return res.first;
        res.first->next = new ListNode(res.second);
        return res.first;
    }
};
