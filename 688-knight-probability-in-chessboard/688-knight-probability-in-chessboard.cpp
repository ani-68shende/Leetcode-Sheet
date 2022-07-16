class Solution {
public:
    double f(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<double>>>& dp){
        if(startRow >= m || startColumn >= n || startRow < 0 || startColumn < 0)return 0;
        if(maxMove == 0)return 1;
        if(dp[startRow][startColumn][maxMove]!=-1)return dp[startRow][startColumn][maxMove];
        double total = 0;
        total += 0.125*f(m, n, maxMove-1, startRow-1, startColumn-2, dp);
        total += 0.125*f(m, n, maxMove-1, startRow-1, startColumn+2, dp);
        total += 0.125*f(m, n, maxMove-1, startRow+1, startColumn-2, dp);
        total += 0.125*f(m, n, maxMove-1, startRow+1, startColumn+2, dp);
        total += 0.125*f(m, n, maxMove-1, startRow-2, startColumn-1, dp);
        total += 0.125*f(m, n, maxMove-1, startRow+2, startColumn-1, dp);
        total += 0.125*f(m, n, maxMove-1, startRow-2, startColumn+1, dp);
        total += 0.125*f(m, n, maxMove-1, startRow+2, startColumn+1, dp);
        return dp[startRow][startColumn][maxMove] = total;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n+1, vector<vector<double>>(n+1, vector<double>(k+1, -1)));
        return f(n, n, k, row, column, dp); 
    }
};