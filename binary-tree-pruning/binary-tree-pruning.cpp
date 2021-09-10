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
    TreeNode* pruneTree(TreeNode* root) {
        int cnt = cntOne(root);
        return cnt?root:NULL;
    }
    int cntOne(TreeNode* root){
        if(!root) return 0;
        int l=0,r=0;
        if(root->left){
            l = cntOne(root->left);
            // if(root->left->val==1) l=1;
        }
        if(root->right){ 
            r = cntOne(root->right);
            // if(root->right->val==1) r=1;
        }
        if(l!=1) root->left = NULL;
        if(r!=1) root->right = NULL;
        return max({l,r,root->val});
    }
};