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
// const int MAX_N = 120;
class Solution {
public:

    Node* cloneGraph(Node* node) {
        vector<bool> mark(110);
        queue<Node*> q;
        vector<Node*> ans(110);
        if(node!=NULL)
            q.push(node);

        while(q.size()>0){
            Node* top = q.front(); q.pop();
            Node* cp = new Node(top->val);
            mark[top->val] = true;
            ans[top->val] = cp;
            cout<<cp->val<<endl;
            for(auto& u: top->neighbors){
                if(mark[u->val] && ans[u->val] != NULL){
                    ans[u->val]->neighbors.push_back(cp);
                    cp->neighbors.push_back(ans[u->val]);
                }
                else if(!mark[u->val]){
                    mark[u->val] = true;
                    q.push(u);
                }
            }
        }
        return ans[1];


    }
};
