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
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        ListNode* t1, *t2;
        while(temp){
            temp = temp->next;
            count++;
        }
        int k1 = k;
        int k2 = count-k+1;
        temp = head;
        while(temp){
            k1--;
            k2--;
            if(k1 == 0){
                t1 = temp;
            }
            if(k2 == 0){
                t2 = temp;
            }
            temp = temp->next;
        }
        swap(t1->val, t2->val);
        return head;
    }
};