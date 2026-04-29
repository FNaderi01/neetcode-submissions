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
    bool isValidRec(TreeNode* root, int& maxVal, int& minVal) {
        if(root == NULL) {
            return true;
        }

        if((root->left != NULL && root->left->val >= root->val) || 
           (root->right != NULL && root->right->val <= root->val)) {
            return false;
        }
        int maxLeft = INT_MIN;
        int minLeft = INT_MAX;
        bool isLeftValid = isValidRec(root->left, maxLeft, minLeft);
        if(!isLeftValid || maxLeft >= root->val) {
            return false;
        }

        int maxRight = INT_MIN;
        int minRight = INT_MAX;
        bool isRightValid = isValidRec(root->right, maxRight, minRight);
        if(!isRightValid || minRight <= root->val) {
            return false;
        }

        maxVal = max(max(maxRight, maxLeft), root->val);
        minVal = min(min(minRight, minLeft), root->val);
        return true;
        
    }

public:
    bool isValidBST(TreeNode* root) {
        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        return isValidRec(root, maxVal, minVal);
    }
};
