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
        m[NULL] = NULL;
        Node* cur = head;
        while(cur!=NULL){
            Node* temp = new Node(cur->val);
            m[cur] = temp;
            cur = cur->next;
        }
        cur = head;
        while(cur != NULL){
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return m[head];
    }
};
