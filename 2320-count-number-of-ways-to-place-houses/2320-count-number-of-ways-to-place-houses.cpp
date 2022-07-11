class Solution {
public:
    int mod = 1e9+7;
    int countHousePlacements(int n) {
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = (dp[i-2] + dp[i-1])%mod;
        }
        return (1LL*dp[n]*dp[n])%mod;
    }
};