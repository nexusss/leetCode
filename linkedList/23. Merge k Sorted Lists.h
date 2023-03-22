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
    ListNode* merge2Lists(ListNode *l1, ListNode *l2){
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        auto head = l1->val < l2->val ? l1 : l2;
        
        head->next = l1->val < l2->val ? merge2Lists(l1->next, l2) : merge2Lists(l1, l2->next);
        
        return head;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return nullptr;
        }
        
        auto res = lists[0];
        
        for (size_t i = 1; i < lists.size(); ++i){
            res = merge2Lists(res, lists[i]);
        }
        
        return res;
        /*priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto &list: lists){
            auto curList = list;
            
            while(curList != nullptr){
                pq.emplace(curList->val);
                curList = curList->next;
            }
        }
        if (pq.empty()){
            return nullptr;
        }
        ListNode *res = new ListNode(pq.top());
        pq.pop();
        auto ans = res;
        while(!pq.empty()){
            res->next = new ListNode(pq.top());
            pq.pop();
            res = res->next;
        }
        
        return ans;*/
    }
};