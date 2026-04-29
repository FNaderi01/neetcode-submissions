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

class Solution {
public:
    bool getKthSmallest(TreeNode* root, int k, vector<int>& v) {
        if(root == NULL) {
            return false;
        }

        if(getKthSmallest(root->left, k, v)) {
            return true;
        }

        v.push_back(root->val);
        if(v.size() == k) {
            return true;
        }

        return getKthSmallest(root->right, k, v);


    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        bool found = getKthSmallest(root, k, v);
        return v[v.size() - 1];
    }
};
