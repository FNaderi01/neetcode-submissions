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
    void countGoodNodes(TreeNode* root, int& cnt, multiset<int>& orderedPath) {
        if(root == NULL) {
            return;
        } 
        orderedPath.insert(root->val);
        int maxV = *orderedPath.rbegin();
        if(maxV <= root->val) {
            cnt++;
        }
        countGoodNodes(root->left, cnt, orderedPath);
        countGoodNodes(root->right, cnt, orderedPath);

        orderedPath.erase(orderedPath.find(root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        multiset<int> orderedPath;
        countGoodNodes(root, cnt, orderedPath);
        return cnt;
        
    }
};
