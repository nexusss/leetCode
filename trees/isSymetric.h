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
    bool isSymmetric(TreeNode *left, TreeNode *right){
        if (left == nullptr && right == nullptr){
            return true;
        }
        else if (left != nullptr && right != nullptr){
            if (left->val == right->val){
                return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
            
            }
        }
        
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return false;
        
        return    isSymmetric(root->left, root->right);     
    }
};
#endif // MAXDEPTH_H
