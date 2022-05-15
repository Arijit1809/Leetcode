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
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = getTreeDepth(root,0);
        cout<<maxDepth<<endl;
        int sumOfDeepestLeaves = 0;
        getSumOfDeepestLeaves(root,0,maxDepth,sumOfDeepestLeaves);
        return sumOfDeepestLeaves;
    }
    
     int getTreeDepth(TreeNode* node,int currDepth){
        if(!node->left && !node->right) return currDepth;
        int leftMaxDepth = node->left ? getTreeDepth(node->left,currDepth+1) : 0;
        int rightMaxDepth = node->right ? getTreeDepth(node->right,currDepth+1) :0 ;
        return max(leftMaxDepth,rightMaxDepth);
    }
    
    void getSumOfDeepestLeaves(TreeNode* node, int currDepth, int maxDepth, int &sumOfDeepestLeaves){
        if(!node) return;
        if(currDepth == maxDepth){
            sumOfDeepestLeaves+=node->val;
            return;
        }
        if(node->left){
            getSumOfDeepestLeaves(node->left,currDepth+1,maxDepth,sumOfDeepestLeaves);
        }
        if(node->right){
            getSumOfDeepestLeaves(node->right,currDepth+1,maxDepth,sumOfDeepestLeaves);
        }
        return;
    }
};