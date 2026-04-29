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
    TreeNode* buildRec(int preS, int preE, int inS, int inE, vector<int>& preorder, vector<int>& inorder) {
        // cout<<preS<<" "<<preE<<" "<<inS<<" "<<inE<<endl;
        if(inS > inE) {
            return NULL;
        }
        int rootVal = preorder[preS];
        TreeNode* root = new TreeNode(rootVal);
        int rootIdx = 0;
        for(int i = inS; i <= inE; i++) {
            if(inorder[i] == rootVal) {
                rootIdx = i;
                break;
            }
        }
        int leftSize = rootIdx - inS;
        int rightSize = (inE - inS) - leftSize;
        root->left = buildRec(preS + 1, preS + leftSize - 1, inS, inS + leftSize - 1, preorder, inorder);
        root->right = buildRec(preS + leftSize + 1, preE, inS + leftSize + 1, inE, preorder, inorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return buildRec(0, n - 1, 0, n - 1, preorder, inorder);
    }
};
