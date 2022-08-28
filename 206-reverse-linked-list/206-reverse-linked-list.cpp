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
        while(cur){
            cur -> next = p;
            p = cur;
            cur = nex;
            if(nex!=NULL){
                nex = nex -> next;
            }else break;
        }
        return p;
    }
};