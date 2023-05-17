#define ll long long int
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<ll>v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        ll maxu = 0;
        ll n = v.size();
        for(ll i = 0 ; i < n/2 ; i++){
            ll sum = v[i]+v[n-i-1];
            maxu = max(maxu, sum);
        }
        return maxu;
    }
};