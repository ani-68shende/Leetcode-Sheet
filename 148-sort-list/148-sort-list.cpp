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
    ListNode* merge_bhai_aajao(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-101);
        ListNode* curr = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                curr -> next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1)curr->next = l1;
        if(l2)curr -> next = l2;
        return dummy-> next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* slow = head;
        // as we need the second list's head to be next node; // if can't remember then learn it XD
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // bach gaya nahi toh slow dhoka de deeta
        ListNode* second = slow -> next;
        slow->next = NULL;
        ListNode* first = head;
        first = sortList(first);
        second = sortList(second);
        return merge_bhai_aajao(first, second);
    }
};