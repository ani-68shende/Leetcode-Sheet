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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>>p;
        for(auto x : lists){
            while(x){
                p.push(x->val);
                x = x->next;
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode *dum = dummy;
        while(p.size())
        {
            int pq = p.top();
            p.pop();
            ListNode* temp = new ListNode(pq);
            dum ->next = temp;
            dum = temp;
        }
        return dummy->next;
    }
};