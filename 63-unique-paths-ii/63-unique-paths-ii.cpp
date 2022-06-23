class Solution {
public:
    // tabulation --
    
    
    int f(int i, int j, vector<vector<int>>& og, vector<vector<int>>& dp){
        if(i >= 0 && j >= 0 && og[i][j] == 1)return 0;
        if(i == 0 && j == 0)return 1;
        if(i < 0 || j < 0)return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int top = f(i-1, j, og, dp);
        int left = f(i, j-1, og, dp);
        return dp[i][j] = top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        int n = og[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(og[i][j] == 1){
                    dp[i][j] = 0;
                }else if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }else{
                    int top = 0, left = 0;
                    if(i>=1)top = dp[i-1][j];
                    if(j>=1)left = dp[i][j-1];
                    dp[i][j] = top + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};