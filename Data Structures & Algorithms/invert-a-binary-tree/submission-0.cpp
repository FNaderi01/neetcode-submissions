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

    TreeNode* recInvert(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        TreeNode* leftRes = recInvert(root->left);
        TreeNode* rightRes = recInvert(root->right);

        root->right = leftRes;
        root->left = rightRes;

        return root;

    }

public:
    TreeNode* invertTree(TreeNode* root) {
        return recInvert(root);
    }
};
