class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int maxSum = INT_MIN,level =1,maxLevel =1;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int currSum =0;
            for(int i = 0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                currSum+=node->val;
            } 
            if(maxSum<currSum){
                maxSum = currSum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};