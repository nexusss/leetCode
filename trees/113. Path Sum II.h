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
    void dfs(TreeNode* root, int targetSum, int currentSum, vector<int> path, vector<vector<int>> &result){
        if (root == nullptr){
            return;
        }
        
        currentSum += root->val;
        path.emplace_back(root->val);
        if (targetSum == currentSum && root->left == nullptr && root->right == nullptr){
            result.emplace_back(path);
        }
        else{
            dfs(root->left, targetSum, currentSum, path, result);
            dfs(root->right, targetSum, currentSum, path, result);
        }
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr){
            return {};
        }
        
        vector<vector<int>> result;
        dfs(root, targetSum, 0, {}, result);
        return result;
    }
};