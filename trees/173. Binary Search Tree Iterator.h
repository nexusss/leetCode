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
class BSTIterator {
    queue <int> q;
public:
    void bst(TreeNode* root){
        if (root == nullptr){
            return;
        }

        bst(root->left);
        q.push(root->val);
        bst(root->right);

    }

    BSTIterator(TreeNode* root) {
        bst(root);
    }
    
    int next() {
        if (q.empty()){
            return 0;
        }

        auto top = q.front();
        q.pop();
        return top;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */