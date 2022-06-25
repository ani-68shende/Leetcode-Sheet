class Solution {
public:
    
    //tabulation
    
    
    // int f(int ind, int target, vector<int> nums, vector<vector<int>>& dp){
    //     if(target == 0)return 1;
    //     if(ind == 0){
    //         if(target%nums[ind] == 0)return 1;
    //         else return 0;
    //     }
    //     if(dp[ind][target]!=-1)return dp[ind][target];
    //     int notTake = f(ind-1, target, nums, dp);
    //     int take = 0;
    //     if(target >= nums[ind]){
    //         take = f(ind, target-nums[ind], nums, dp);
    //     }
    //     return dp[ind][target] = take+notTake;
    // }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int target = amount;
        vector<vector<int>>dp(n, vector<int>(amount+1,0));
        for(int j = 0 ; j <= target ; j++){
            if(j%coins[0] == 0)
                dp[0][j] = 1;
        }
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j <= target ; j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(j >= coins[i]){
                    take = dp[i][j-coins[i]];
                }
                dp[i][j] = take+notTake;
            }
        }
        return dp[n-1][target];
    }
};