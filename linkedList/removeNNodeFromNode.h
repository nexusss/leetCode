#ifndef REMOVENNODEFROMNODE_H
#define REMOVENNODEFROMNODE_H
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head;
        ListNode *fast=head;
        for(int i=1;i<=n;i++)
            fast=fast->next;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        if(fast==NULL&&slow==head)
            head=head->next;
        else
            slow->next=slow->next->next;

        return head;
    }
};
#endif // REMOVENNODEFROMNODE_H
