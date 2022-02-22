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
    void inorder(TreeNode* root, vector<int> &result, int k){
        
        if(root == nullptr)
            return;
        
        inorder(root->left,result, k);
        
        result.push_back(root->val);
        inorder(root->right,result, k);
        
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        inorder(root, result, k);
        
        return result.at(k - 1);
    }
};
#endif // MAXDEPTH_H
