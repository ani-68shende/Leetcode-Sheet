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
    int numComponents(ListNode* head, vector<int>& nums) {
        int count(0);
        ListNode* temp = head;
        unordered_map<int, int>mp;
        for(auto x : nums)mp[x]+=1;
        ListNode* prev = temp;
        while(temp!=NULL){
            int flag(0);
            while(temp && mp.find(temp->val) != mp.end()){
                flag++;
                temp = temp->next;
            }
            if(flag)count++;
            if(temp)
            temp=temp->next;
        }
        return count;
    }
};