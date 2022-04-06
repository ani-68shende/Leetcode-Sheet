class Solution {
public:
    long long razor(int idx, vector<int> &prices, int buy, vector<vector<vector<int>>>&dp, int k){
        if(idx == prices.size() || k == 0)return 0;
        int profit = 0;
        if(dp[idx][buy][k]!= -1)return dp[idx][buy][k];
        if(buy){
            profit = max(-prices[idx]+razor(idx+1, prices, 0, dp, k),
                        0+ +razor(idx+1, prices, 1, dp, k));
        }else{
            profit = max(prices[idx] + razor(idx+1, prices, 1, dp, k-1),
                        0 + razor(idx +1, prices, 0, dp, k));
        }
        return dp[idx][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int buy = 1;
        int idx = 0;
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2, vector<int>(k+1, -1)));
        return razor(idx, prices, buy, dp, k);
    }
};