/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return NULL;
        }
        vector<Node*> all(101, NULL);
        queue<Node*> q;
        q.push(node);
        all[1] = new Node(node->val);

        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();

            Node* copy = all[cur->val];

            for(Node* nei : cur->neighbors) {
                if(all[nei->val] != NULL) {
                    copy->neighbors.push_back(all[nei->val]);
                } else {
                    Node* newNeigh = new Node(nei->val);
                    q.push(nei);
                    copy->neighbors.push_back(newNeigh);
                    all[nei->val] = newNeigh;
                }
            }
        }

        return all[1];
    }
};
