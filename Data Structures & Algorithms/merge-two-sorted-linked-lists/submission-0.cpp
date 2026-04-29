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
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1==NULL && list2==NULL) return NULL;

        ListNode* root = new ListNode();
        ListNode* cur = root;
        ListNode* r1 = list1;
        ListNode* r2 = list2;
        ListNode* prev = NULL;
        while(r1!= NULL && r2!=NULL){
            if(r1->val<= r2->val){
                cur->val = r1->val;
                r1 = r1->next;
            }
            else{
                cur->val = r2->val;
                r2 = r2->next;
            }

            if(prev!=NULL)
                prev->next = cur;
            prev = cur;
            ListNode* new_node = new ListNode();
            cur = new_node;
        }
        while(r1!=NULL){
            cur->val = r1->val;
            r1 = r1->next;
            prev->next = cur;
            prev = cur;
            ListNode* new_node = new ListNode();
            cur = new_node;
        }
        while(r2!=NULL){
            cur->val = r2->val;
            r2 = r2->next;
            prev->next = cur;
            prev = cur;
            ListNode* new_node = new ListNode();
            cur = new_node;
        }
        return root;
    }
};
