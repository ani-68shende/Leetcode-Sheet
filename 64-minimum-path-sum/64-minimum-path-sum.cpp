class Solution {
public:
    // tabulation
    // int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    //     if(i == 0 && j == 0)return grid[i][j];
    //     if(i < 0 || j < 0)return 1e8;
    //     if(dp[i][j]!= -1)return dp[i][j];
    //     int top = grid[i][j] + f(i-1, j, grid, dp);
    //     int left = grid[i][j] + f(i, j-1, grid, dp);
    //     return dp[i][j] = min(top, left);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }else{
                    int top = 1e8, left = 1e8;
                    if(i>=1){
                        top = grid[i][j] + dp[i-1][j];
                    }
                    if(j>=1){
                        left = grid[i][j] + dp[i][j-1];
                    }
                    dp[i][j] = min(top, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};