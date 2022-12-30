typedef long long ll;
const ll mod = 1e9 + 7;
class Solution {
public:
    ll k;
    vector<int>nums;
    vector<vector<ll>>dp;
    ll expo(ll a, ll b, ll mod = 1e9+7) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
    ll ff(ll ind, ll sum){
        if(sum < 0){
            return 0;
        }
        if(ind == nums.size()){
            return sum == 0;
        }
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        ll take = ff(ind+1, sum-nums[ind]);
        ll nottake = ff(ind+1,sum);
        return dp[ind][sum]=(take+nottake)%mod;
    }
    //all - invalid
    int countPartitions(vector<int>& num, int l) {
        int n=num.size();
        dp.resize(n+1, vector<ll>(l+1, -1));
        nums=num;
        k=l;
        ll total(0);for(auto x : num)total+=x;
        if(total < 2*k)return 0;
        ll sum = (expo(2,n))%mod;
        ll extra = 0;
        for(ll i = 0 ; i < k; i++){
            extra = (extra+ff(0, i))%mod;
        }
        return mod_sub(sum,extra*2,mod);
    }
};