class Solution {
public:
    long long int dp[60];
    long long int f(int n){
        if(n == 0)return 1;
        if(n <= 1){
            return 0;
        }
        if(dp[n]!=-1)return dp[n];
        long long int teo = 2*f(n-2);
        long long int thr = 3*f(n-3);
        return dp[n] = max(teo, thr);
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        if(n == 2 || n == 3)return n-1;
        return f(n);
    }
};