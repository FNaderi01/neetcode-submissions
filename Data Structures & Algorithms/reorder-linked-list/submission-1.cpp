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
        while(cur!=NULL){
            cout<<cur->val<<",";
            cur = cur->next;
        }

        return prev;

    }
    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && (fast->next)!= nullptr){
            // cout<<slow->val<<endl;
            // cout<<fast->val<<endl;
            slow = slow ->next;
            fast = fast->next->next;
            // if(fast->next==NULL) cout<<"last:"<<fast->val<<endl;
        }
        ListNode* second = slow->next;
        // int cnt =0;
        // while(cur!=NULL){
        //     cnt++;
        //     cur = cur->next;
        // }
        // cur = head;
        // for(int i =1; i<=(cnt/2); i++){
        //     cur = cur->next;
        // }
        slow->next = NULL;
        ListNode* cur = head;
        ListNode* mid = reverse(second);
        // cout<<(mid==NULL)<<endl;
        // cur = head;
        while(!(mid == nullptr)){
            
            ListNode* t = cur->next;
            ListNode* p = mid->next;
            // if(t==nullptr) {cout<<"t is NULL:"<<cur->val<<endl; break;}
            // if(p==nullptr) {cout<<"p is NULL:"<<mid->val<<endl;break;}

            cur->next = mid;
            mid->next = t;
            cur = t;
            mid = p;
            // if(mid == nullptr) {cout<<"mid became null"<<endl;break;}
        }
    }
};
