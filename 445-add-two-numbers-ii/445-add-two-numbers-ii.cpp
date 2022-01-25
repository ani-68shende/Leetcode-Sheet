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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* p = NULL;
        ListNode* cur = head;
        ListNode* nex = head -> next;
        while(true){
            cur -> next = p;
            p = cur;
            cur = nex;
            if(nex!=NULL){
                nex = nex -> next;
            }else break;
        }
        return p;
    }
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* l1 = reverseList(head1);
        ListNode* l2 = reverseList(head2);
        ListNode* dummy = new ListNode(-1);//for just an example
        ListNode* temp = dummy;
        int carry = 0;
        while(l1|| l2 || carry){
            int sum_curr = 0;
            if(l1){
                sum_curr += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum_curr += l2->val;
                l2 = l2->next;
            }
            sum_curr += carry;
            int value = sum_curr%10;
            carry = sum_curr/10;
            ListNode * node = new ListNode(value);
            temp ->next = node;
            temp  = node;
        }
        return reverseList(dummy-> next);
    }
};