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
    ListNode* reverse(ListNode* head){
        ListNode * prev = NULL, * curr = head, * nex = head->next;
        while(1){
            curr->next = prev;
            prev = curr;
            curr = nex;
            if(nex)nex = nex->next;
            else break;
        }return prev;
    }
    ListNode* plusOne(ListNode* head) {
        ListNode*h = reverse(head);
        int carry = 1;
        ListNode*temp = h;
        ListNode* prev = h;
        while(temp){
            // cout << temp->val << " ";
            int sum = temp->val+carry;
            carry = sum/10;
            temp -> val = sum%10;
            prev = temp;
            temp =temp-> next;
        }
        if(carry){
            prev->next = new ListNode(carry);
        }
        ListNode*hh = reverse(h);
        return hh;
    }
};