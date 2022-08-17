class Solution {
public:
    //recursive
    int f(int i, vector<int> & cost, vector<int> & dp){
        if(i == cost.size()-1)return cost[i];
        if(i >  cost.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ones = cost[i]+f(i+1, cost, dp);
        int sec  = cost[i]+f(i+2, cost, dp);
        return dp[i] = min(ones, sec);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(), -1);
        return min(f(0, cost, dp),f(1, cost, dp));
    }
};