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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(-1000);
        ListNode*yt = dummy;
        dummy->next = list1;
        int count1 = a-1, count2 = b;
        ListNode * temp1 = list1,* temp11 = list1;
        while(count1-- && temp1->next){
            temp1=temp1->next;
        }
        while(count2-- && temp11->next){
            temp11=temp11->next;
        }
        temp1->next = list2;
        while(list2->next){
            list2=list2->next;
        }
        list2->next=temp11->next;
        return yt->next;
    }
};