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
    pair<int,int> findMax(vector<int> &nums){
        int max= 0;
        int place=0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
                place = i;
            }
        }
        return {max,place};
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        pair<int,int> p = findMax(nums);
        TreeNode* node = new TreeNode(p.first);
        vector<int> vl(nums.begin(),nums.begin()+p.second);
        vector<int> vr(nums.begin()+p.second+1,nums.end());
        node->left = constructMaximumBinaryTree(vl);
        node->right = constructMaximumBinaryTree(vr);
        return node;
    }
};