#ifndef MERGE_H
#define MERGE_H
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        auto tmp1 = list1;
        auto tmp2 = list2;

        ListNode *result = new ListNode();
        auto returnRes = result;


        while (tmp1 != nullptr and tmp2 != nullptr){
            if (tmp1->val < tmp2->val){
                result->next = tmp1;
                tmp1 = tmp1->next;
            }
            else{
                result->next = tmp2;
                tmp2 = tmp2->next;
            }
            result = result->next;

        }

        while (tmp1 != nullptr){
            result->next = tmp1;
            tmp1 = tmp1->next;
            result = result->next;
        }

        while (tmp2 != nullptr){
            result->next = tmp2;
            tmp2 = tmp2->next;
            result = result->next;
        }

        return returnRes->next;
    }
};
#endif // MERGE_H
