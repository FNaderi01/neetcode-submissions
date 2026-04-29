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
    pair<int, int> dfs(TreeNode* root){
        if(root == NULL) return {-1, 0};
        int h=0;
        int d=0;
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        h = max(left.first, right.first)+1;
        d = max(left.second, right.second);
        d = max(d, left.first+right.first +2);
        return {h, d};

    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).second;

    }
};
