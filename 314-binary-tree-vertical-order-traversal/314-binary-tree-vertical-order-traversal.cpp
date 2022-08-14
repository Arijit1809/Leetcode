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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map< int, vector<TreeNode*> > nodeLevels;
        TreeNode* rootNode = root;
        queue< pair< TreeNode*, int > > levels;
        if(root == NULL){
            return {};
        }
        levels.push({root, 0});
        while(!levels.empty()){
            pair<TreeNode*, int> currNodePair = levels.front();
            levels.pop();
            TreeNode* currNode = currNodePair.first;
            int currLevel = currNodePair.second;
            nodeLevels[currLevel].push_back(currNode);
            if(currNode->left){
                levels.push({currNode->left, currLevel-1});
            }
            if(currNode->right){
                levels.push({currNode->right, currLevel+1});
            }
        }
        vector<vector<int>> ans;
        for(auto nodeLevel : nodeLevels){
            vector<TreeNode*> currLevel = nodeLevel.second;
            vector<int> currLevelAns;
            for(TreeNode* node : currLevel){
                currLevelAns.push_back(node->val);
            }
            ans.push_back(currLevelAns);
        }
        return ans;
    }
};