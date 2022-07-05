class Solution {
public:
    //recursive
    int f(int i1, int i2, int j, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){
        if(i1 < 0 || i1 >= grid[0].size() || i2 < 0 || i2 >= grid[0].size() || j >= grid.size())return 0;
        if(dp[i1][i2][j]!=-1)return dp[i1][i2][j];
        int maxu = 0;
        for(int i = -1 ; i <= 1 ; i++){
            for(int k = -1 ; k <= 1 ; k++){
                int val = 0;
                if(i1 == i2)
                    val = grid[j][i1];
                else 
                    val = grid[j][i1] + grid[j][i2];
                maxu = max(maxu,val + f(i1+i, i2+k, j+1, grid, dp));
            }
        }
        return dp[i1][i2][j] = maxu;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int i1 = 0, i2 = 0, j = 0;
        vector<vector<vector<int>>>dp (grid[0].size(),vector<vector<int>>(grid[0].size(), vector<int>(grid.size(), -1)));
        return f(i1, -1+grid[0].size(), j, grid, dp);
    }
};