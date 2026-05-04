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
        vector<Node*> copiedNodes(101, NULL);
        queue<Node*> q;

        if(node) {
            q.push(node);
            copiedNodes[1] = new Node(node->val);
        }

        while(!q.empty()) {
            Node* cur = q.front();
            Node* copy = copiedNodes[cur->val];
            q.pop();

            for(Node* nei : cur->neighbors) {
                Node* copyNei = copiedNodes[nei->val];
                if(copyNei != NULL) {
                    copy->neighbors.push_back(copyNei);
                } else {
                    Node* newNeigh = new Node(nei->val);
                    copy->neighbors.push_back(newNeigh);
                    copiedNodes[nei->val] = newNeigh;
                    q.push(nei);
                }
            }
        }

        return copiedNodes[1];
    }
};
