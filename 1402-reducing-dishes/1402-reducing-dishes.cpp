class Solution {
public:
    int f(int i, vector<int>& ss, int time, vector<vector<int>>& dp){
        if(i < 0)return 0;
        if(dp[i][time]!=-1)return dp[i][time];
        int notTake = f(i-1, ss, time, dp);
        int take = ss[i]*time + f(i-1, ss, time+1, dp);
        return dp[i][time] = max(take, notTake);
    }
    int maxSatisfaction(vector<int>& ss) {
        sort(ss.begin(), ss.end(), greater<int>());
        vector<vector<int>> dp(ss.size(), vector<int>(ss.size()+1, -1));
        return f(ss.size()-1, ss, 1, dp);
    }
};