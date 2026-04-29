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
    void getPath(TreeNode* root, int target, vector<TreeNode*>& v) {
        if(root == NULL) {
            return;
        }
        v.push_back(root);
        if(target == root->val) {
            return;
        }
        else if(target < root->val) {
            getPath(root->left, target, v);
        } else {
            getPath(root->right, target, v);
        }

        return;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vp;
        vector<TreeNode*> vq;
        getPath(root, p->val, vp);
        getPath(root, q->val, vq);
        
        if(vp.size() > vq.size()) {
            swap(vp, vq);
        }

        while(vq.size() > vp.size()) {
            vq.pop_back();
        }

        while(1) {
            if(vq.back() == vp.back()) {
                return vq.back();
            }
            vq.pop_back();
            vp.pop_back();
        }
        
        return NULL;
        
    }
};
