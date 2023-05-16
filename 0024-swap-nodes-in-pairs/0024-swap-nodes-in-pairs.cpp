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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* prev = head, *nex1 = head -> next, *nex2 = head -> next -> next;
        nex1 -> next = prev;
        prev ->next = nex2;
        prev -> next = swapPairs(nex2);
        return nex1;
    }
};