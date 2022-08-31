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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = countnode(head);
        ListNode *temp = head;
        if(n <= k){
            vector<ListNode*>v(k, NULL);
            int i =0 ;
            while(head){
                ListNode* newNode = new ListNode(head->val);
                v[i] = newNode;
                head = head->next;
                i++;
            }
            return v;
        }
        else{
            vector<ListNode*>v;
            int parts = n/k;
            int rem = n%k;
            int flag = 0;
            while(temp){
                int d = parts;
                if(flag < rem){
                    flag++;
                    d += 1;
                    ListNode* newNode = new ListNode(-1000);
                    //aree dummy to bhul i gaya;
                    ListNode* dummy = newNode;
                    while(temp && d){
                        d--;
                        newNode ->next = new ListNode(temp->val);
                        temp = temp->next;
                        newNode = newNode->next;
                    }
                    v.push_back(dummy->next);
                }else{
                    ListNode* newNode = new ListNode(-1000);
                    ListNode* dummy = newNode;
                    while(temp && d){
                        d--;
                        newNode ->next = new ListNode(temp->val);
                        temp = temp->next;
                        newNode = newNode->next;
                    }
                    v.push_back(dummy->next);
                }
            }
            return v;
        }
        return {};
    }
};