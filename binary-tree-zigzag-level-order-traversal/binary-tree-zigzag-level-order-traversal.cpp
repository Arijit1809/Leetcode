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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> z;
            for(int i =0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                z.push_back(temp->val);
            }
            flag?reverse(z.begin(),z.end()):void();
            v.push_back(z);
            flag = !flag;
        }
        return v;
    }
};