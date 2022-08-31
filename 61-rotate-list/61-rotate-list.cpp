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
    int countnode(ListNode* head){
        int count= 0 ;
        while(head){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        ListNode* slow = head;
        ListNode* fast = head;
        int n = countnode(head);
        k = k%n;
        k = (n-k)%n;
        if(k == 0)return head;
        int kk = k;
        // cout << kk << endl;
        while(kk-->1){
            fast = fast->next;
        }
        // cout << fast->val << endl;
        slow = fast->next;
        fast -> next = NULL;
        ListNode* newhead = slow;
        while(slow && slow->next){
            slow = slow->next;
        }
        slow->next = head;
        return newhead;
    }
};