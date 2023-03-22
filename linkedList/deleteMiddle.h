#ifndef DELETENODE_H
#define DELETENODE_H
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
    ListNode* deleteMiddle(ListNode* head) {
        
        if (head == nullptr ){
            return head;
        }
        
        if(head->next == nullptr){
            delete head;
            return nullptr;
        }
        
        auto slow = head;
        auto fast = head->next->next;
        
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        auto delnode = slow->next;
        slow->next = slow->next->next;
        delete delnode;
        return head;
        
    }
};
#endif // DELETENODE_H
