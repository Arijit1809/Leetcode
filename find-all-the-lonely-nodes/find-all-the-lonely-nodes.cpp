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
    void dfs(TreeNode* root, vector<int>& lonely) {
        if (!root)
            return;
        if (root->left && !root->right)
            lonely.push_back(root->left->val);
        if (!root->left && root->right)
            lonely.push_back(root->right->val);
        dfs(root->left, lonely);
        dfs(root->right, lonely);
    }
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> lonely;
        dfs(root, lonely);
        return lonely;
    }
};