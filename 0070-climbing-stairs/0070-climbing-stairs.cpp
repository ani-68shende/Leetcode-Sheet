class Solution {
public:
    int helper(int n, vector<int> & dp){
        if(n < 0)return 0;
        if(n == 0)return 1;
        if(dp[n]!=-1)return dp[n];
        int ones = helper(n-1, dp);
        int seco = helper(n-2, dp);
        return dp[n]=ones + seco;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return helper(n, dp);
    }
};