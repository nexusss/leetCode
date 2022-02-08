#ifndef REVERSE_H
#define REVERSE_H
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if (head == nullptr)
            return head;
        
        auto curr = head;
        auto start = head;
        
        vector <ListNode*> tmp;
        
        while (curr != nullptr and curr->next != nullptr){
            tmp.push_back(curr->next);
            if (curr->next->next == nullptr)
                break;
            curr->next = curr->next->next;
            curr = curr->next;
        }
        
        for(ListNode* t: tmp){
            t->next = nullptr;
            curr->next = t;
            curr = curr->next;
        }
    
        
        return start;
    }
};
#endif // REVERSE_H
