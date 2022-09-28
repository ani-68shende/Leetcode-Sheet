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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *temp = head;
        ListNode *temp2 = head;
        while(temp!=NULL)
        {
            //exhausting this temp to find the length of the linked list
            temp = temp -> next;
            count++;
        }
        if(n == count)
        {
            return head->next;
        }
        int i = 1;
        while(i<count-n)
        {
            //using this temp to reach just before the node to be deleted
            temp2 = temp2->next;
            i++;
        }
        temp2 -> next = temp2-> next -> next;
        return head;
    }
};