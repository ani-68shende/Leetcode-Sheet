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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int n = countnode(head);
        if(n <= 2)return {-1,-1};
        vector<int>ss;
        ListNode* prev = head, *curr = head->next, * nex = curr->next;
        int i = 1;
        while(nex){
            if(prev->val < curr->val && curr->val > nex->val){
                ss.push_back(i);
            }else if(prev->val > curr->val && curr->val < nex->val){
                ss.push_back(i);
            }
            prev = curr;
            curr = nex;
            nex = nex->next;
            i++;
        }
        if(ss.size()<2)
            return {-1, -1};
        int mini = INT_MAX;
        int maxi = 0;
        for(int i = 1 ; i < ss.size(); i++){
            mini = min(mini, ss[i]-ss[i-1]);
        }
        return {mini, ss[ss.size()-1]-ss[0]};
    }
};