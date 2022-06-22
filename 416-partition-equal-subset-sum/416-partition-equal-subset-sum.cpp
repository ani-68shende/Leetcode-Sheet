class Solution {
public:
    //memoization soln
    bool f(int ind, int target, vector<int>& weights, vector<vector<int>>&dp){
        if(target == 0)return dp[ind][target] = 1;
        if(ind == 0){
            return dp[ind][target] = (weights[0]== target);
        }
        if(dp[ind][target] != -1)return dp[ind][target];
        bool notPick = f(ind-1, target, weights, dp);
        bool pick = 0;
        if(target >= weights[ind]){
            pick = f(ind-1, target-weights[ind], weights, dp);
        }
        return dp[ind][target] = notPick | pick;
    }
    
    bool canPartition(vector<int>& weights) {
        int sum = 0;
        int n = weights.size();
        for(auto x : weights){
            sum += x;
        }
        if(sum%2){
            return false;
        }
        vector<vector<int>>dp(n, vector<int>((sum/2)+1,-1));
        return f(weights.size()-1, sum/2, weights, dp);
    }
};