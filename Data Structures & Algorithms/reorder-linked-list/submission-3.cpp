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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        
        ListNode* cur = head;
        
        while(cur != nullptr) {
            v.push_back(cur);
            cur = cur->next;
        }
        
        int n = v.size();
        // cout<<n<<endl;
        for(int i = n - 1; i > (n / 2); i--) {
            // cout<<v[i]->val<<endl;
            ListNode* tmp = v[(n - 1) - i]->next;
            v[(n - 1) - i]->next = v[i];
            v[i]->next = tmp;
        }

        v[n / 2]->next = nullptr;
    }
};
