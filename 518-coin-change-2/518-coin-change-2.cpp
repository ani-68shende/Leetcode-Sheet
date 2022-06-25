class Solution {
public:
    // memoization
    int f(int ind, int target, vector<int> nums, vector<vector<int>>& dp){
        if(target == 0)return 1;
        if(ind == 0){
            if(target%nums[ind] == 0)return 1;
            else return 0;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int notTake = f(ind-1, target, nums, dp);
        int take = 0;
        if(target >= nums[ind]){
            take = f(ind, target-nums[ind], nums, dp);
        }
        return dp[ind][target] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        return f(-1+n, amount, coins, dp);
    }
};