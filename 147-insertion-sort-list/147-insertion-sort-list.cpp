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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-10001);
        ListNode* tempo = dummy;
        while(head){
            ListNode* nex = head->next;
            ListNode* temp = dummy;
            while(temp->next && head->val > temp->next->val){
                temp = temp->next;
            }
            head->next = temp->next; //1 life changing moves
            temp->next = head; // 2 this one also
            head = nex;
        }
        return dummy->next;
    }
};