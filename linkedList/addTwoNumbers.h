#ifndef ADDTWONUMBERS_H
#define ADDTWONUMBERS_H
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        auto currRl1 = l1;
        auto currRl2 = l2;

        ListNode *result = new ListNode();
        ListNode *currResult = result;
        bool carryFlag = false;

        while (currRl1 != nullptr or currRl2 != nullptr){

            auto val = currRl1 != nullptr ? currRl1->val : 0;
            val += currRl2 != nullptr ? currRl2->val : 0;

            if(carryFlag)
                val += 1;

            if (val > 9){
                carryFlag = true;
                val -= 10;


            }
            else{
                carryFlag = false;

            }
            currResult->next = new ListNode(val);


            currResult = currResult->next;
            if(currRl1 != nullptr)
                currRl1 = currRl1->next;
            if(currRl2 != nullptr)
                currRl2 = currRl2->next;


        }
        if(carryFlag)
            currResult->next = new ListNode(1);

        return result->next;
    }
};
#endif // ADDTWONUMBERS_H
