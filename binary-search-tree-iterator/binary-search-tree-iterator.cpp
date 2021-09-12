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
class BSTIterator {
public:
    stack<int> bsts;
    BSTIterator(TreeNode* root) {
        bstHelper(root);
    }
    void bstHelper(TreeNode* root){
        if(!root) return;
        bstHelper(root->right);
        bsts.push(root->val);
        bstHelper(root->left);
    }
    int next() {
        int top = bsts.top();
        bsts.pop();
        return top;
    }
    bool hasNext() {
        return bsts.empty()?false:true;        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */