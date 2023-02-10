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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1 = new ListNode(-1001), * h2 = new ListNode(-1001);
        ListNode* l1=h1, *l2=h2;
        
        while(head){
            if(head->val < x){
                l1->next = head;
                l1=l1->next;
            }else{
                l2->next = head;
                l2=l2->next;
            }
            head=head->next;
        }
        l1->next = h2->next;
        l2->next = NULL;
        return h1->next;
    }
};