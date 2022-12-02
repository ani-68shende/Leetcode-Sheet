/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 **/
class Solution {
public:
    ListNode* reverse(ListNode* s, ListNode* e) {
        ListNode *p = NULL, *c = s, *n;
        while(p!=e){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1){
            return head;
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        // dummy ko bhi bhav milra idhar
        ListNode* beforeStart = dummy, *e = dummy->next;
        int i = 0;
        while(e){
            i++;
            if(i%k==0){
                ListNode* s = beforeStart->next,* temp = e->next;
                reverse(s, e);
                beforeStart->next = e;
                s->next = temp;
                beforeStart = s;
                e = s; 
            }
            e = e->next;
        }
        return dummy->next;
    }
};