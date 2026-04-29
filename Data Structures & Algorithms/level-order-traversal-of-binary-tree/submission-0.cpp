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
    void traverse(TreeNode* root, int idx, vector<vector<int>>& v) {
        if(root == NULL) {
            return;
        }
        if(v.size() <= idx) {
            vector<int> newLevel;
            newLevel.push_back(root->val);
            v.push_back(newLevel);
        } else {
            v[idx].push_back(root->val);
        }
        traverse(root->left, idx + 1, v);
        traverse(root->right, idx + 1, v);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>  ans;
        traverse(root, 0, ans);
        return ans;
    }
};
