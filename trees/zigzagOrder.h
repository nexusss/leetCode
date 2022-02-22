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
    struct Tmp{
        TreeNode * root;
        int level;
        Tmp(TreeNode * root, int level): root(root), level(level){}
    };
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        
        stack<Tmp> currentlevel;
        stack<Tmp> nextlevel;
        // push the root
        currentlevel.emplace(root, 0);

        // check if stack is empty  
        bool lefttoright = true;
        while (!currentlevel.empty()) {

            // pop out of stack
            TreeNode* temp = currentlevel.top().root;
            int level = currentlevel.top().level;
            currentlevel.pop();

            if (level >= result.size()){
                result.emplace_back(vector<int> ());
            }
            result[level].push_back(temp->val);
            
            // if not null
            if (temp) {

                // print the data in it
                // store data according to current
                // order.
                if (lefttoright) {
                    if (temp->left)
                        nextlevel.emplace(temp->left, level+1);
                    if (temp->right)
                        nextlevel.emplace(temp->right, level+1);
                }
                else {
                    if (temp->right)
                        nextlevel.emplace(temp->right, level+1);
                    if (temp->left)
                        nextlevel.emplace(temp->left, level+1);
                }
            }

            if (currentlevel.empty()) {
                lefttoright = !lefttoright;
                swap(currentlevel, nextlevel);
            }
        }
        return result;
        
    }
};
#endif // MAXDEPTH_H
