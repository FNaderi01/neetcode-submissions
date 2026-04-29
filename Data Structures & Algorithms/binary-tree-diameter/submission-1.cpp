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
    // pair of (depth, diameter)
    pair<int, int> recDiam(TreeNode* node) {
        if(node == NULL) {
            return make_pair(0, 0);
        } 
        if(node->left == NULL and node->right == NULL) {
            return make_pair(1, 0);
        }

        auto pLeft = recDiam(node->left);
        auto pRight = recDiam(node->right);

        pair<int, int> ans;
        ans.first = max(pLeft.first, pRight.first) + 1;

        int included = pLeft.first + pRight.first;
        int notIncluded = max(pLeft.second, pRight.second);
        ans.second = max(included, notIncluded);

        return ans;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> ans = recDiam(root);
        return ans.second;
    }
};
