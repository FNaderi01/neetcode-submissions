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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, vector<ListNode*>> mp;

        for(int i = 0; i < lists.size(); i++) {
            ListNode* cur = lists[i];
            while(cur != NULL) {
                mp[cur->val].push_back(cur);
                cur = cur->next;
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        for(auto x : mp) {
            for(auto y : x.second) {
                if(head == NULL) {
                    head = y;
                    tail = y;
                } else {
                    tail->next = y;
                    tail = y;
                }
            }
        }

        return head;
    }
};
