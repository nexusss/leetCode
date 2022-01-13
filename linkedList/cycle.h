#ifndef CYCLE_H
#define CYCLE_H
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr){
            return false;
        }
        if (head->next == nullptr)
            return false;

        unordered_set <uint64_t> mapAddr;

        auto cur = head;

        while(cur != nullptr){
            uint64_t addr = (uint64_t)cur;
            if (mapAddr.find(addr) != mapAddr.end()){
                return true;
            }
            else{
                mapAddr.insert(addr);
                cur = cur->next;

            }
        }

        return false;
    }
};
#endif // CYCLE_H
