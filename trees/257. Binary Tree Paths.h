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
    
    void dfs(TreeNode* root, string str, vector<string> &res){
        
        if (root == nullptr){
            return;
        }
        if (str.empty()){
            str = to_string(root->val);
        }
        else{
            str += "->" + to_string(root->val);
        }
        
        if (root->left == nullptr && root->right == nullptr){
            res.emplace_back(str);
        }
        else{
            dfs(root->left, str, res);
            dfs(root->right, str, res);
        }
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        
        string str;
        vector <string> res;
        
        dfs(root, str, res);
        
        return res;
        
    }
};