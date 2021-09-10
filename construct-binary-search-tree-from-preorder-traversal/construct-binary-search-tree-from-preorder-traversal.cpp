class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        return helper(preorder,0,preorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder,int l,int r){
        if(l==r) return new TreeNode(preorder[l]);
        if(l>r) return nullptr;
        int rs =r+1;
        int ls = l+1;
        for(int i = l;i<=r;i++){
            if(preorder[i]>preorder[l]){
                rs=i;
                break;
            }
        }
        int le = rs-1;
        TreeNode* node = new TreeNode(preorder[l]);
        node->left = helper(preorder,ls,le);
        node->right = helper(preorder,rs,r);
        return node;
    }
};