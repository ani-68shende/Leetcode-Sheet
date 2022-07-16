class Solution {
public:
    int mod = 1e9+7;
    int f(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>& dp){
        if(maxMove < 0)return 0;
        if(startRow >= m || startColumn >= n || startRow < 0 || startColumn < 0)return 1;
        if(dp[startRow][startColumn][maxMove]!=-1)return dp[startRow][startColumn][maxMove]%mod;
        int total = 0;
        total = (total + f(m, n, maxMove-1, startRow-1, startColumn, dp))%mod;
        total = (total + f(m, n, maxMove-1, startRow+1, startColumn, dp))%mod;
        total = (total +  f(m, n, maxMove-1, startRow, startColumn-1, dp))%mod;
        total = (total + f(m, n, maxMove-1, startRow, startColumn+1, dp))%mod;
        dp[startRow][startColumn][maxMove] = total;
        return dp[startRow][startColumn][maxMove]%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return f(m, n, maxMove, startRow, startColumn, dp); 
    }
};