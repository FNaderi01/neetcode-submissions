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
    bool recIsSame(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        } 
        if(p == NULL || q == NULL || p->val != q->val) {
            return false;
        }

        bool res = recIsSame(p->left, q->left);
        if(res) {
            res = recIsSame(p->right, q->right);
        }

        return res;
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return recIsSame(p, q);
    }
};
