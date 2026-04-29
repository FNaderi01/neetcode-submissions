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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pq;
        queue<TreeNode*> qq;

        pq.push(p);
        qq.push(q);

        while(pq.size() != 0 && qq.size() != 0) {
            TreeNode* pFront = pq.front();
            pq.pop();
            TreeNode* qFront = qq.front();
            qq.pop();

            if(pFront == NULL) {
                if(qFront != NULL) {
                    return false;
                }
            } else {
                if(qFront == NULL) {
                    return false;
                }

                if(pFront->val != qFront->val) {
                    return false;
                }
                pq.push(pFront->left);
                pq.push(pFront->right);
                qq.push(qFront->left);
                qq.push(qFront->right);
            }
        }

        if(pq.size() == 0 && qq.size() == 0) {
            return true;
        }
        return false;
    }
};
