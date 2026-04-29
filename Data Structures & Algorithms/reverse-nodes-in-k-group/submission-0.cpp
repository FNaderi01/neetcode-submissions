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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;

        while(cur != NULL) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* curHead = head;
        int cnt = 1;


        while(cur != NULL && cnt < k) {
            cnt++;
            cur = cur->next;
        }

        ListNode* nextHead = cur->next;
        ListNode* curTail = curHead;
        cur->next = NULL;
        head = reverse(curHead);

        curHead = nextHead;
        cur = nextHead;
        while(cur != NULL) {
            cnt = 1;
            while(cur->next != NULL && cnt < k) {
                cnt++;
                cur = cur->next;
            }

            if(cnt < k) {
                curTail->next = nextHead;
                return head;
            }

            nextHead = cur->next;
            cur->next = NULL;
            ListNode* rev = reverse(curHead);
            curTail->next = rev;
            curTail = curHead;

            curHead = nextHead;
            cur = nextHead;

        }

        return head;
        
    }
};
