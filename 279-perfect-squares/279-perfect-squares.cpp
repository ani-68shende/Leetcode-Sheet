class Solution {
public:
    int f(vector<int> & all, int n, int i, vector<vector<int>> & dp){
        if(n < 0 || i >= all.size())return 1e7;
        if(n == 0)return 0;
        if(dp[i][n]!=-1)return dp[i][n];
        int notpick= f(all, n, i+1, dp);
        int pick = 1e7;
        if(n-all[i]>=0){
            pick = 1 + f(all, n-all[i], i, dp);
        }
        return dp[i][n] = min(pick, notpick);
    }
    int numSquares(int n) {
        vector<int>all;
        for(int i = 1 ; i <= 100 ; i++){
            all.push_back(i*i);
        }
        vector<vector<int>>dp(101, vector<int>(10001, -1));
        reverse(all.begin(), all.end());
        return f(all, n, 0, dp);
    }
};