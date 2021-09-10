class FindElements {
    std::bitset< (2<<20) > vv;
    
    void recover(TreeNode* n, int ii) {
        if(!n) { return; }
        
        vv[ii] = true;
        recover(n->left, ii*2+1);
        recover(n->right, ii*2+2);
    }
public:
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return vv[target] == true;
    }
};
