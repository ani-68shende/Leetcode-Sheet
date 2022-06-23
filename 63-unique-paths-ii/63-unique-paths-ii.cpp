class Solution {
public:
    // memoize 
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
        return f(m-1 ,n-1 ,og, dp);
    }
};