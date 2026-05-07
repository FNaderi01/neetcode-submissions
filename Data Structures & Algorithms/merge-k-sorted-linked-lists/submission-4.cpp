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
        auto comp = [](ListNode* l, ListNode* r) {
            return l->val > r->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        for(ListNode* l : lists) {
            if(l != NULL) {
                pq.push(l);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();

            tail->next = cur;
            tail = tail->next;

            if(cur->next != NULL) {
                pq.push(cur->next);
            }
        }

        return dummy.next;
    }
};
