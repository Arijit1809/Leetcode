class Solution {
public:
    vector<TreeNode*> result;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        sort(to_delete.begin(),to_delete.end());
        delNodesHelper(root,to_delete);
        return result;
    }
    void delNodesHelper(TreeNode* root,vector<int>& to_delete,TreeNode* parent = NULL){
        if(!root) return;
        if(deleteNode(to_delete,root->val)){
            if(parent){
                if(parent->right==root) parent->right=nullptr;
                if(parent->left==root) parent->left=nullptr;
            }
            delNodesHelper(root->left,to_delete,NULL);
            delNodesHelper(root->right,to_delete,NULL);
            root->left=root->right=nullptr;
            root=nullptr;
        }else{
            if(!parent) result.push_back(root);
            delNodesHelper(root->left,to_delete,root);
            delNodesHelper(root->right,to_delete,root);
        }
    }
    bool deleteNode(vector<int>& to_delete,int deleteElem){
        return binary_search(to_delete.begin(),to_delete.end(),deleteElem);
    }
};