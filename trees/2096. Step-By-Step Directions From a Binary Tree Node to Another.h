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
   /* TreeNode* findLCA(TreeNode* root, int startValue, int destValue){
        if (root == nullptr){
            return nullptr;
        }
        
        if (root->val == startValue || root->val == destValue) return root;
        
        auto lca1 = findLCA(root->left, startValue, destValue);
        auto lca2 = findLCA(root->right, startValue, destValue);
        
        if (lca1 != nullptr && lca2 != nullptr) return root;
        if (lca1 != nullptr) return lca1;
        
        return lca2;
        
    }
    
    
    string dfs(TreeNode* root, int searchValue, string&& direction){
        if (root == nullptr){
            return "";
        }
        if (root->val == searchValue){
            return direction;
        }
        auto left = dfs(root->left, searchValue, "L");
            if(!left.empty()){
                return direction + left;
            }
        auto right = dfs(root->right, searchValue, "R");
            if (!right.empty()){
                return direction + right;
            }
        return "";
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto lca = findLCA(root, startValue, destValue);
        if (lca == nullptr){
            return "";
        }
        cout << "1";
        auto startst = dfs(lca, startValue, "");
        cout << startst << endl;
        auto destst = dfs(lca, destValue, "");
        cout << destst << endl;
    
        
        for(auto &c: startst){
            c = 'U';
        }
       // cout << startst << " " << destst << endl;
        
        return startst + destst;        
    }*/};
#endif // MAXDEPTH_H
