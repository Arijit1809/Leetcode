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
class FindElements {
public:
    vector<int> v;
    FindElements(TreeNode* root) {
        root->val = 0;
        TreeNode* node = helper(root);
        sort(v.begin(),v.end());
    }
    TreeNode* helper(TreeNode* root){
        if(root->left){
            root->left->val=2*root->val+1;
            helper(root->left); 
        }
        if(root->right){
            root->right->val=2*root->val+2;
            helper(root->right);  
        }
        v.push_back(root->val);
        return root;
    }
    bool find(int target) {
        return binary_search(v.begin(),v.end(),target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */