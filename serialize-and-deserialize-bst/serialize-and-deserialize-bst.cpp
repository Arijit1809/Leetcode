class Codec {
public:
    void encode(TreeNode* root, string &str){
        if(root == NULL)
            return;
        str += to_string(root->val);
        str += "-";
        encode(root->left, str);
        encode(root->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        encode(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        stringstream ss(data);
        string value;
        while(getline(ss, value, '-')){
            root = insert(root, stoi(value));
        }
        return root;
    }
    
    TreeNode* insert(TreeNode* root, int data){
        if(root == NULL){
            root = new TreeNode(data);
            return root;
        }
        if(root->val > data){
            root->left = insert(root->left, data);
            return root;
        }
        else{
            root->right = insert(root->right, data);
            return root;
        }
    }
};