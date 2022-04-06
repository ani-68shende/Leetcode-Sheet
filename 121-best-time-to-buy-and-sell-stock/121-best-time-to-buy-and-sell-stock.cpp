class Solution {
public:
    // nw let us move towards the optimal approach 
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = prices[0];
        for(int i = 0 ; i < prices.size() ; i++){
            ans = max(ans, prices[i]-mini);
            mini = min(mini, prices[i]);
        }
        return ans;
    }
};