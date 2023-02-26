#define ll long long int
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<ll, ll>>v;
        ll n = profits.size();
        for(ll i = 0 ; i < n ; i++){
            v.push_back({(ll)capital[i], (ll)profits[i]});
        }
        sort(v.begin(), v.end());
        ll ini = w;
        ll j = 0;
        ll tot = 0;
        priority_queue<pair<ll, ll>>pq;
        int flag = 0;
        while(k){
            while(j < n && v[j].first <= ini){
                pq.push({v[j].second, v[j].first});
                j++;
            }
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