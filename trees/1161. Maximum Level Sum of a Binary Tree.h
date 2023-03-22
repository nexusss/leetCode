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
    int maxLevelSum(TreeNode* root) {
        
        queue <pair<TreeNode *, int>> q;
        
        q.emplace(root, 0);
        unordered_map <int, int> levelsMaxValue;
        while (!q.empty()){
            auto top = q.front();
            int level = top.second;
            levelsMaxValue[level] += top.first->val;
            q.pop();
            
            if(top.first->left != nullptr)
                q.emplace(top.first->left, level + 1);
            
            if(top.first->right != nullptr)
                q.emplace(top.first->right, level + 1);
            
        }
        
        int maxValueLevel = numeric_limits<int>::min();
        int maxLevel = 0;
        for(auto &levels: levelsMaxValue){
            cout << "levels.second" << levels.second << " " << levels.first << endl;
            if (levels.second > maxValueLevel){
                maxLevel = levels.first;
                maxValueLevel = levels.second;
            }
            else if (levels.second == maxValueLevel && maxLevel > levels.first){
                maxLevel = levels.first;
            }
        
        }
        return maxLevel + 1;
    }
};
#endif // MAXDEPTH_H
