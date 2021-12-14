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
    int result = 0;
    void rec(TreeNode* root,int low,int high){
        if(root==NULL) return;
        if(root->val<=high && root->val>=low) result+=root->val;
        if(root->val>=low) rec(root->left,low,high);
        if(root->val<=high) rec(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        rec(root,low,high);
        return result;
    }
};