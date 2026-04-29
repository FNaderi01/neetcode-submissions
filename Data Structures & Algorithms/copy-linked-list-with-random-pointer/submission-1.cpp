/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;

        Node* cur = head;
        Node* resHead = NULL;
        Node* resTail = NULL;

        while(cur != NULL) {
            Node* cp = new Node(cur->val);
            m[cur] = cp;
            cur = cur->next;

            if(resHead == NULL) {
                resHead = cp;
                resTail = cp;
            } else {
                resTail->next = cp;
                resTail = cp;
            }
        }

        cur = head;
        Node* curCp = resHead;

        while(cur != NULL) {
            curCp->random = m[cur->random];
            cur = cur->next;
            curCp = curCp->next;
        }

        return resHead;


    }
};
