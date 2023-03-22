struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    void bst(TreeNode* root, string &result){
        if (root == nullptr){
            result += + "null-";
            return;
        }
        result += std::to_string(root->val) + "-";
        bst(root->left, result);
        bst(root->right, result);
    }

    void bst2(TreeNode* root,const string &result, size_t &pos){

        if (root == nullptr){
            return;
        }

        root->left = getNode(result, pos);
        bst2(root->left, result, pos);

        root->right = getNode(result, pos);
        bst2(root->right, result, pos);
    }

    TreeNode* getNode(const string &data,size_t &pos){
        const auto start = pos;
        while(pos < data.size() and data[pos] != '-'){
            pos++;
        }
        string sub = data.substr(start, pos - start);
        pos++;
        if(sub == "null"){
            return nullptr;
        }

        return new TreeNode(stoi(sub));
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        bst(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null-"){
            return nullptr;
        }
        size_t pos = 0;
        TreeNode *tree = getNode(data, pos);
        bst2(tree, data, pos);
        return tree;
    }
};
