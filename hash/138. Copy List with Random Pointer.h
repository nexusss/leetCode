/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> mp;

public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }

        auto cur = head;
        auto res = new Node(head->val);
        mp[head] = res;

        auto returnNode = res;
        
        while(cur->next != nullptr){
            res->next = new Node(cur->next->val);
            mp[cur->next] = res->next;
            res = res->next;
            cur = cur->next;
        }

        cur = head;
        res = returnNode;
        
        while(cur != nullptr){
            if(cur->random != nullptr){
                auto find = mp.find(cur->random);
                if(find != mp.end()){
                    res->random = find->second;
                }
            }
            res = res->next;
            cur = cur->next;
        }

        return returnNode;
    }
};