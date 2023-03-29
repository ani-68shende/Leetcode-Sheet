class Solution {
public:
    //see previous submission for recur + memo 
    int maxSatisfaction(vector<int>& ss) {
        sort(ss.begin(), ss.end(), greater<int>());
        vector<vector<int>> dp(501, vector<int>(505, 0));
        for(int i = 0 ; i < ss.size() ; i++){
            for(int time = ss.size() ; time >= 1 ; time--){
                int notTake = dp[i][time];
                int take = ss[i]*time + dp[i][time+1];
                dp[i+1][time] = max(take, notTake);
            }
        }
        return dp[ss.size()][1];
    }
};