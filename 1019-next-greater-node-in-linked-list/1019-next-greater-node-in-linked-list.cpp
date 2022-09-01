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
    ListNode* reversenode(ListNode* head){
        ListNode* prev = NULL, *curr = head, *nex;
        while(curr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head= reversenode(head);
        vector<int>ans;
        stack<int>s;
        ListNode* temp = head;
        while(temp){
            while(!s.empty() && temp->val >= s.top()){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(0);
                s.push(temp->val);
            }else{
                ans.push_back(s.top());
                s.push(temp->val);
            }
            temp = temp->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};