#define ll long long int
class Solution {
public:
    static bool cmp(pair<ll, ll> &a, pair<ll, ll> &b){
        // if(a.first == b.first){
        //     return a.second >= b.second;
        // }
        return a.first < b.first;
    }
    ll find(vector<pair<ll, ll>>&v, ll target){
        ll low = 0;
        ll high = v.size() - 1;
        if(v[v.size()-1].first <= target)return v.size()-1;
        ll ans = -1;
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(v[mid].first <= target){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<ll, ll>>v;
        ll n = profits.size();
        for(ll i = 0 ; i < n ; i++){
            v.push_back({(ll)capital[i], (ll)profits[i]});
        }
        sort(v.begin(), v.end(), cmp);
        ll ini = w;
        ll j = 0;
        ll tot = 0;
        priority_queue<pair<ll, ll>>pq;
        int flag = 0;
        while(k){
            ll indx = find(v, ini);
            // if(indx==-1){
            //     break;
            // }
            while(j <= indx){
                pq.push({v[j].second, v[j].first});
                j++;
                if(j == n){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)break;
            if(pq.size()){
                // cout << "yes\n";
                ini += pq.top().first;
                pq.pop();
                k--;
            }else{
                break;
            }
        }
        while(pq.size() && k){
            ini += pq.top().first;
            pq.pop();
            k--;
        }
        return ini;
    }
};