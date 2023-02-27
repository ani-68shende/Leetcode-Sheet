#define ll long long
ll mod = (ll)1000000007;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int m = nums.size();
        // cout << m << endl;
        vector<ll>pref(m,0), suff(m,0);
        pref[0] = nums[0];
        suff[m-1] = nums[m-1];
        for(int i = 1 ; i < m ; i++){
            pref[i] = pref[i-1] + nums[i];
            suff[m-i-1] = suff[m-i] + nums[m-i-1];
        }
        // for(auto x : pref){
        //     cout << x << " ";
        // }
        // cout << "\n";
        // for(auto x : suff){
        //     cout << x << " ";
        // }
        // cout << "\n";
        vector<int>ans(m,0);
        ans[0] = (suff[0]-nums[0]*m);
        for(ll i = 1 ; i < m-1 ; i++){
            ll left = (i)*nums[i] - pref[i-1];
            ll right = suff[i+1] - (m-i-1)*nums[i];
            // cout << left << " " << right;
            ans[i] = abs(left) + abs(right);
        }
        ans[m-1] = (abs(pref[m-1]-nums[m-1]*m));
        return ans;
    }
};