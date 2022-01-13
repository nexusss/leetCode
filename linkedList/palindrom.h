#ifndef PALINDROM_H
#define PALINDROM_H
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
    ListNode *findHalfList(ListNode* head){
        auto fast = head;
        auto slow = head;

        while (true){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == nullptr)
                break;
            if(fast->next == nullptr)
                break;
        }

        return slow;
    }

    ListNode *revertList(ListNode *head){
        vector<int> arr;
        while (head != NULL) {
            arr.push_back(head->val);
            head = head->next;
        }
        ListNode *root= NULL;
        for(int i = 0; i < arr.size() ; ++i) {
            ListNode* temp = new ListNode;
            temp->val = arr[i];
            temp->next = root;
            root = temp;
        }
        return root;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr){
            return false;
        }
        if (head->next == nullptr){
            return true;
        }

        auto firstPart = findHalfList(head);
        auto revSecondPart = revertList(firstPart);
        auto p1 = head;

        while(revSecondPart != nullptr){
            if(revSecondPart->val != p1->val){
                return false;
            }
            revSecondPart = revSecondPart->next;
            p1 = p1->next;
        }
        return true;
    }
};
#endif // PALINDROM_H
