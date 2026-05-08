/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> ps;

        Node* cur = p;
        while(cur != NULL) {
            ps.insert(cur);
            cur = cur->parent;
        }

        cur = q;
        while(cur != NULL) {
            if(ps.find(cur) != ps.end()) {
                return cur;
            }
            cur = cur->parent;
        }

        return NULL;

        
    }
};