class Solution {
public:
    int N, M;
    int mod = 1e9+7;
    long long dfs(int i, int j, vector<vector<int>>& grid, vector<vector<long long>>& dp){
        if(dp[i][j]!=-1)return dp[i][j];
        long long tota = 1;
        vector<int>x={0,0,1,-1}, y={1,-1,0,0};
        for(int k = 0 ; k < 4 ; k++){
            int nr = i + x[k];
            int nc = j + y[k];
            if(nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] > grid[i][j]){
                tota = max(tota,1+dfs(nr, nc, grid, dp));
            }
        }
        return dp[i][j] = tota;
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        vector<vector<long long>>dp(N, vector<long long>(M,-1));
        long long maxu = 0;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                maxu = max(maxu, dfs(i, j , grid, dp));
            }
        }
        return maxu;
    }
};