class Solution {
public:
    //memoization (do not do dp[i][j]=1 || 0)
    int f(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0)return 1;
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int top = f(i-1, j, dp);
        int left = f(i, j-1, dp);
        return dp[i][j] = top+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return f(m-1, n-1, dp);
    }
};