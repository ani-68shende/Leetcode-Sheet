#define ll long long
class Solution {
public:
    bool check(int n, vector<int>& batteries, ll cost, vector<ll> & v, ll &kk){
        ll lap = 0;
        ll counto = 0;
        ll new_cost = 0;
        for(ll j = 0 ; j < n ; j++){
            if(cost-v[j] > 0)
            new_cost += cost-v[j];
        }
        return new_cost <= kk;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll low = 0, high = 1e14, ans = 0;
        sort(batteries.begin(), batteries.end(), greater<int>());
        vector<ll>v;
        ll i = 0;
        for( ; i < n ; i++){
            v.push_back(batteries[i]);
        }
        ll kk = 0;
        for( ; i < batteries.size() ; i++){
            kk += batteries[i];
        }
        while(low <= high){
            ll mid = low+(high-low)/2;
            if(check(n, batteries, mid, v, kk)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};