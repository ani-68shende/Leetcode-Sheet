class Solution {
public:
    int f(int i, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(i == 0){
            if(target%coins[i] == 0)return target/coins[i];
            else return 1e8;
        }
        if(dp[i][target] != -1)return dp[i][target];
        int notPick = 0 + f(i-1,target,coins, dp);
        int pick = 1e8;
        if(target-coins[i]>=0){
            pick = 1 + f(i, target-coins[i], coins, dp);

        }
        return dp[i][target] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int target = amount;
        if(target == 0)return 0;
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        int z = f(n-1, target,coins,dp);
        return z==1e8 ? -1 : z;
    }
};