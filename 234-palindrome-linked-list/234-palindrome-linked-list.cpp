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
    // here the intuition is to use the mid position i.e. slow and fast pointers 
    //using the reverse in between just leaves us with comapring the nodes one by one;
    ListNode* rev(ListNode *head){
        ListNode *prev = NULL;
        while(head){
            ListNode* temp = head->next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *iterator = head;
        ListNode * slow = head;
        ListNode * fast = head;
        int count = 0;
        ListNode * counter = head;
        while(counter){
            count++;
            counter= counter -> next;
        }
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *newerr = head;
        if(count%2){
            slow = rev(slow->next);
        }
        else
        slow = rev(slow);
        while(slow){
            if(slow->val == newerr->val){
                newerr = newerr->next;
                slow = slow->next;
            }else{
                return false;
            }
        }
        return true;
    }
};