/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if (root == nullptr){
            return root;
        }
        
        queue <pair <Node *, int>> q;
        
        q.emplace(root, 0);
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if (!q.empty() && q.front().second == top.second){
                top.first->next = q.front().first;
            }
            
            if (top.first->left != nullptr)
                q.emplace(top.first->left, top.second + 1);
            
            if (top.first->right != nullptr)
                q.emplace(top.first->right, top.second + 1);
            
        }
        
        return root;
    }
};