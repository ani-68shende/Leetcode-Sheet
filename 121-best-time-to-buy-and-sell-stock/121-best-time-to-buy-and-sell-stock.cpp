class Solution {
public:
    // nw let us move towards the optimal approach 
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int sumu = 0;
        for(auto i : prices){
            sumu = max(sumu, i-mini);
            mini = min(i, mini);
        }
        return sumu;
    }
};