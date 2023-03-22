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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        
        auto fastIter = head;
        auto slowIter = head;
        
        int listLen = 0;
        
        while (fastIter != nullptr){
            fastIter = fastIter->next;
            ++listLen;
        }
        
        fastIter = head;
        
        if (k >= listLen){
            
            k = k % listLen;
        }
        //cout << "k " << k << " " << listLen << " " << (k % listLen);
        while (k > 0){
            --k;
            fastIter = fastIter->next;
        }
        
        if (fastIter == slowIter){
            return head;
        }
        
        while (fastIter->next != nullptr){
            fastIter = fastIter->next;
            slowIter = slowIter->next;
        }
        
        
        auto res = slowIter->next;
        slowIter->next = nullptr;
        fastIter->next = head;
        
        return res;
    }
};