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
    //main thing is while removing the between elements remove them from left pointer to the node where the sum gets repeated
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, ListNode*>mp;
        int ps = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* t = dummy;
        while(t){
            ps += t->val;
            if(mp.find(ps) != mp.end()){
                ListNode* start = mp[ps];
                ListNode* temp = start;
                int sum = ps;
                start = start-> next;
                while(start!=t){
                    sum += start->val;
                    mp.erase(sum);
                    start = start -> next;
                }
                temp->next = t->next;
            }else{
                mp[ps] = t;
            }
            t = t->next;
        }
        return dummy->next;
    }
};