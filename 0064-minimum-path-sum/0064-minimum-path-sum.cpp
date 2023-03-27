class Solution {
public:
    
    // SPAce Optimization NInja Technique
    
    
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
        vector<int> prev(n, -1);
        vector<int> curr(n, -1);
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0){
                    curr[j] = grid[i][j];
                }else{
                    int top = 1e8, left = 1e8;
                    if(i>=1){
                        top = grid[i][j] + prev[j];
                    }
                    if(j>=1){
                        left = grid[i][j] + curr[j-1];
                    }
                    curr[j] = min(top, left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};