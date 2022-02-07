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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;


        int rL = maxDepth(root->left);
        int rD = maxDepth(root->right);

        return max(rL + 1, rD +1 );
    }
};
#endif // MAXDEPTH_H
