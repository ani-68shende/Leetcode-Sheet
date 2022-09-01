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
    // dummy vai
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* dummy = new ListNode(-100);
        dummy->next = head;
        ListNode* prev = dummy, *curr = dummy->next;
        while(curr){
            bool gaya_tha_kya = false;
            while(curr && curr->next && curr->val==curr->next->val){
                gaya_tha_kya = true;
                curr = curr->next;
            }
            if(gaya_tha_kya)
                prev->  next = curr->next;
            else{
                prev = prev->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};