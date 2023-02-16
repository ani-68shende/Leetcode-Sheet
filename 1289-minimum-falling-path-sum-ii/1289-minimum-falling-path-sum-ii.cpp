class Solution {
public:
    int n;
    int dp[1002][1002];
    int la(int i, int precv, vector<vector<int>>& grid){
        if(i == n){
            return 0;
        }
        if(dp[i][precv+1]!=-1)return dp[i][precv+1];
        int mini = 1e5;
        for(int k = 0 ; k < n ; k++){
            if(precv!=k){
                int val = grid[i][k] + la(i+1, k, grid);
                mini = min(mini, val);
            }
        }
        return dp[i][precv+1] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        return la(0, -1, grid);
    }
};