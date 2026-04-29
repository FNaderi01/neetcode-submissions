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
typedef long long ll;
class Solution {
    bool isValidRec(TreeNode* root, ll& maxVal, ll& minVal) {
        if(root == NULL) {
            return true;
        }

        if((root->left != NULL && root->left->val >= root->val) || 
           (root->right != NULL && root->right->val <= root->val)) {
            return false;
        }
        ll maxLeft = LLONG_MIN;
        ll minLeft = LLONG_MAX;
        bool isLeftValid = isValidRec(root->left, maxLeft, minLeft);
        if(!isLeftValid || maxLeft >= root->val) {
            return false;
        }

        ll maxRight = LLONG_MIN;
        ll minRight = LLONG_MAX;
        bool isRightValid = isValidRec(root->right, maxRight, minRight);
        if(!isRightValid || minRight <= root->val) {
            return false;
        }

        maxVal = max(max(maxRight, maxLeft), (ll)(root->val));
        minVal = min(min(minRight, minLeft), (ll)(root->val));
        return true;
        
    }

public:
    bool isValidBST(TreeNode* root) {
        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;
        return isValidRec(root, maxVal, minVal);
    }
};
