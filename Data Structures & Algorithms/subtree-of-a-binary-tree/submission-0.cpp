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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        } 
        if(p == NULL || q == NULL || p->val != q->val) {
            return false;
        }

        if(isSameTree(p->left, q->left)) {
            return isSameTree(p->right, q->right);
        }

        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isSameTree(root, subRoot)) {
            return true;
        }

        if(root == NULL) {
            return false;
        }

        if(isSubtree(root->left, subRoot)) {
            return true;
        }
        return isSubtree(root->right, subRoot);

    }
};
