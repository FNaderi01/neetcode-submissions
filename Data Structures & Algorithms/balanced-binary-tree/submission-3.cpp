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
    int computeHeight(TreeNode* node, bool& ans) {
        if(node == NULL) {
            return 0;
        }
        // if(node->left == NULL && node->right == NULL) {
        //     return 1;
        // }

        int lh = computeHeight(node->left, ans);
        int rh = computeHeight(node->right, ans);

        if(abs(lh - rh) > 1) {
            ans = false;
        }

        return max(lh, rh) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int h = computeHeight(root, ans);
        return ans;
    }
};
