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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr or headB == nullptr){
            return nullptr;
        }

        unordered_set<ListNode *> mp;

        auto curA = headA;
        auto curB = headB;

        while(curA != nullptr or curB != nullptr){
            if (curA == curB){
                
                return curA;
            }
            
            if(curA != nullptr){
                auto findA = mp.find(curA);
                if(findA != mp.end()){
                    
                    return curA;
                }
                mp.insert(curA);
                curA = curA->next;
            }
            if(curB != nullptr){
                auto findB = mp.find(curB);
                if(findB != mp.end()){
                    
                    return curB;
                }
                mp.insert(curB);
                curB = curB->next;
            }

            
        }
        
        return nullptr;
    }
};