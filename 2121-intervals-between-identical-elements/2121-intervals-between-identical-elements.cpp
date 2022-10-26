#define ll long long
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<ll, vector<ll>>ind;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            ind[arr[i]].push_back(i);
        }
        vector<ll>pref(n,0), suff(n,0);
        pref[0] = 0, suff[n-1] = 0;
        for(auto x : ind){
            vector<ll>v = x.second;
            int n = v.size();
            for(int i = 1 ; i < n ;i++){
                pref[v[i]] = pref[v[i-1]]+(long long)((v[i]-v[i-1])*i);
            }
            for(int i = n-2 ; i>= 0 ; i--){
                suff[v[i]] = suff[v[i+1]]+(long long)((n-i-1)*(v[i+1]-v[i]));
            }
        }
        vector<ll>ans(n, 0);
        for(int i = 0 ; i < n ; i++)ans[i] = suff[i] + pref[i];
        return ans;
    }
};