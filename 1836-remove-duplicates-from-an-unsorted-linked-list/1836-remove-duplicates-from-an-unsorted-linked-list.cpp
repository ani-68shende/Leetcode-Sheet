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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int>mp;
        ListNode* temp_head = new ListNode(-1);
        temp_head -> next = head;
        while(head){
            mp[head->val]++;
            head=head->next;
        }
        head = temp_head; // restart again
        while(head->next){
            if(mp[head->next->val]>=2){
                head->next = head->next->next;
            }else{
                head = head->next;
            }
        }
        return temp_head->next;
    }
};