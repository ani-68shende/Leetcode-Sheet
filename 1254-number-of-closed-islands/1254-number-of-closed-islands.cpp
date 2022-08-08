class Solution {
public:
    bool dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i >=0 && j>=0 && i< n && j < m && grid[i][j]==1)return true;
        if(i == 0 || j == 0 || i== -1+n || j == -1+m)return false;
        grid[i][j] = 1;
        bool x1 = dfs(i+1,j,n,m,grid);
        bool x2 = dfs(i,j+1,n,m,grid);
        bool x3 = dfs(i-1,j,n,m,grid);
        bool x4 = dfs(i,j-1,n,m,grid);
        return x1 && x2 && x3 && x4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int enclave=0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if((i == n-1) || (i == 0) || (j == m-1) || (j == 0)){
                    continue;
                }
                if(grid[i][j] == 0){
                    if(dfs(i,j,n,m,grid))enclave+=1;
                }
            }
        }
        return enclave;
    }
};