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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        
        if (head->next == nullptr){
            return head;
        }
        
        auto cur = head;
        auto res = head->next;
        ListNode* prev = nullptr;
        while (cur && cur->next != nullptr){

            auto nextnext = cur->next->next;
            auto next = cur->next;
            cur->next = nextnext;
        
            next->next = cur;
            
            if (prev != nullptr){
                prev->next = next;
            }
            prev = cur;
            cur = cur->next;
        }
        return res;
    }
};#endif // REVERSE_H
