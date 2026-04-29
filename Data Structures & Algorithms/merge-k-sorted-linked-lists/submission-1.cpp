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
    ListNode* mergeTwo(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) {
            return list2;
        } else if(list2 == NULL) {
            return list1;
        }

        ListNode* resHead = NULL;
        ListNode* resTail = NULL;

        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        while(cur1 != NULL && cur2 != NULL) {
            ListNode* resCur = NULL;
            if(cur1->val <= cur2->val) {
                resCur = cur1;
                cur1 = cur1->next;
            } else {
                resCur = cur2;
                cur2 = cur2->next;
            }

            if(resHead == NULL) {
                resHead = resCur;
                resTail = resCur;
            } else {
                resTail->next = resCur;
                resTail = resCur;
            }
        }

        if(cur1 != NULL) {
            resTail->next = cur1;
        } else if(cur2 != NULL) {
            resTail->next = cur2;
        }


        return resHead;
    }

    ListNode* mergeSort(int s, int e, vector<ListNode*>& lists) {
        if(s == e) {
            return lists[s];
        }

        int mid = (s + e) / 2;
        ListNode* left = mergeSort(s, mid, lists);
        ListNode* right = mergeSort(mid + 1, e, lists);

        return mergeTwo(left, right);
    }


public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        return mergeSort(0, lists.size() - 1, lists);
    }
};
