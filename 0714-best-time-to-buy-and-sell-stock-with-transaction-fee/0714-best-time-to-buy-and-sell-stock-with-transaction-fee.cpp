class Solution {
public:
    int fees = 0;
    long long razor(int idx, vector<int> &prices, int buy, vector<vector<int>>&dp){
        if(idx == prices.size())return 0;
        int profit = 0;
        if(dp[idx][buy]!= -1)return dp[idx][buy];
        if(buy){
            profit = max(-prices[idx]-fees+razor(idx+1, prices, 0, dp),
                        0+ +razor(idx+1, prices, 1, dp));
        }else{
            profit = max(prices[idx] + razor(idx+1, prices, 1, dp),
                        0 + razor(idx +1, prices, 0, dp));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int buy = 1;
        int idx = 0;
        fees = fee;
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return razor(idx, prices, buy, dp);
    }
};