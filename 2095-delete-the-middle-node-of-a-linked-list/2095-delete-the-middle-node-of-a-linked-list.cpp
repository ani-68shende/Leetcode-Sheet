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
    int c(ListNode* head)
    {
        int count = 0;
        while (head != NULL) {
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* deleteMiddle(ListNode* head) {
    if (head == NULL)
        return NULL;
    ListNode* dummy = head;
    int n = c(head);
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    int m = n/2;
    while (m-- > 1) {
        head = head->next;
    }
    head->next = head->next->next;
 
    return dummy;
    }
};