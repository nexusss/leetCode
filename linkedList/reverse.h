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
    ListNode* reverseList(ListNode* head) {

        if( head == nullptr or head->next == nullptr){
            return head;
        }

        ListNode *prev = nullptr;
        auto curr = head;
        while(curr != nullptr){

            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }

        return prev;

    }
};
#endif // REVERSE_H
