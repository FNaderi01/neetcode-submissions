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
    void countGoodNodes(TreeNode* root, int& cnt, int maxVal) {
        if(root == NULL) {
            return;
        } 
        if(root->val >= maxVal) {
            cnt++;
            maxVal = root->val;
        }
        countGoodNodes(root->left, cnt, maxVal);
        countGoodNodes(root->right, cnt, maxVal);
    }
public:
    int goodNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int cnt = 0;
        countGoodNodes(root, cnt, root->val);
        return cnt;
        
    }
};
