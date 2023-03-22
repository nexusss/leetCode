#ifndef MAXDEPTH_H
#define MAXDEPTH_H
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

    void dfs(TreeNode* &root, set<int>& to_deleteSet, vector<TreeNode*> &res){
        


        if (root == nullptr){
            return ;
        }
        
        dfs(root->left, to_deleteSet, res);
        dfs(root->right, to_deleteSet, res);

         auto iter = to_deleteSet.find(root->val);
        if (iter != to_deleteSet.end())
        {
            if (root->left)
                res.emplace_back(root->left);
            if (root->right)
                res.emplace_back(root->right);
            
            delete root;
            root = nullptr;
        }   
        
    }

    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> to_deleteSet;
        vector<TreeNode*> result;
        
        for(auto &del: to_delete){
            to_deleteSet.emplace(del);
        }
        
        
        dfs(root, to_deleteSet, result);
        
        if (root)
            result.emplace_back(root);
        
        for(auto &res: result){
            cout << res->val;
        
        }
        
        return result;
        
    }
};
#endif // MAXDEPTH_H
