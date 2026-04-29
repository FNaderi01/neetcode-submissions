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
    pair<int, int> dfs(TreeNode* root) {
        if(root == NULL) return {-INT_MAX, -INT_MAX};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int maxToRoot = max(0, max(left.second, right.second)) + root->val;
        int maxPath = max(max(left.first, right.first), root->val + max(0, left.second) + max(0, right.second));
        return {maxPath, maxToRoot};

    }
    int maxPathSum(TreeNode* root) {
        auto x = dfs(root);
        return x.first;
    }
};
