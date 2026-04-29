/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    void serializeRec(TreeNode* root, string& s) {
        if(root == NULL) {
            s += "N ";
            return;
        }

        s += to_string(root->val) + " ";
        serializeRec(root->left, s);
        serializeRec(root->right, s);
    }
    /* Encodes a tree to a single string. */
    string serialize(TreeNode* root) {
        string s = "";
        serializeRec(root, s);
        return s;
    }

    void splitBySpace(const string& str, queue<string>& tokens) {
        stringstream ss(str);
        string token;
    
        /* The >> operator automatically extracts whitespace-separated words */
        while (ss >> token) {
            tokens.push(token);
        }
    }

    TreeNode* deserializeRec(queue<string> &q) {
        string front = q.front();
        q.pop();
        if(front == "N") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(front));
        root->left = deserializeRec(q);
        root->right = deserializeRec(q);

        return root;
    }

    /* Decodes your encoded data to tree. */
    TreeNode* deserialize(string data) {
        queue<string> q;
        splitBySpace(data, q);

        return deserializeRec(q);
    }
};
