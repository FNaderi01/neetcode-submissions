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
    void getRightView(TreeNode* root, int idx, int& depth, vector<int>& ans) {
        if(root == NULL) {
            return;
        }

        if(depth == idx) {
            depth++;
            ans.push_back(root->val);
        }

        getRightView(root->right, idx + 1, depth, ans);
        getRightView(root->left, idx + 1, depth, ans);
        
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int depth = 0;
        getRightView(root, 0, depth, ans);
        return ans;
    }
};
