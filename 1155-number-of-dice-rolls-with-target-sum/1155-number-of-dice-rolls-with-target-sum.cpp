class Solution {
public:
    //pajwa doing bottom opopop
    long long mod = 1e9+7;
    long long memo_boiz(int M, int N, int X, vector<vector<long long>>& dp){
        if(N == 0){
            if(X == 0)return 1;
            else return 0;
        }
        if(dp[N][X]!=-1)return dp[N][X];
        long long pick = 0;
        for(int i = 1 ; i <= M ; i++){
            if(X-i >= 0)
            pick = (pick + memo_boiz(M, N-1, X-i, dp))%mod;
        }
        return dp[N][X] = pick%mod;
    }
    int numRollsToTarget(int N, int M, int X) {
        vector<vector<long long>>dp(N+1, vector<long long>(X+1, -1));
        return memo_boiz(M, N, X,dp);
    }
};