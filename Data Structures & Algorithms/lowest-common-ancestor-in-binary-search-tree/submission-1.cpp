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
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val <= root->val && q->val >= root->val) {
            return root;
        }

        if(q->val < root->val) {
            return LCA(root->left, p, q);
        } 
        return LCA(root->right, p, q);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) {
            swap(p, q);
        }

        return LCA(root, p, q);
    }
};
