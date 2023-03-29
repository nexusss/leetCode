/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* dfs(Node *node, unordered_map<int, Node*> &visited){
        
        
        
        if (node == nullptr)
            return nullptr;
        Node *resNode = new Node(node->val);
        visited[node->val] = resNode;
        //cout << "node " << node->val << " " << node->neighbors.size() << endl;
        
        
        for (auto &n: node->neighbors){
            auto iter = visited.find(n->val);
            
            if (iter == visited.end()){
                resNode->neighbors.emplace_back(dfs(n, visited));
            }
            else{
                resNode->neighbors.emplace_back(iter->second);
            }
        }
        
        //cout << "resnode " << resNode->val << " " << resNode->neighbors.size() << endl;
        
        return resNode;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node* > visited;
        
        return dfs(node, visited);
    }
};