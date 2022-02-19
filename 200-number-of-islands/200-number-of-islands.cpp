class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<char>>& grid){
        if(i >=0 && j>=0 && i< n && j < m && grid[i][j]=='1')return true;
        return false;
    }
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid){
        grid[i][j] = '0';
        if(isValid(i+1,j,n,m,grid))
            dfs(i+1,j,n,m,grid);
        if(isValid(i,j+1,n,m,grid))
            dfs(i,j+1,n,m,grid);
        if(isValid(i-1,j,n,m,grid))
            dfs(i-1,j,n,m,grid);
        if(isValid(i,j-1,n,m,grid))
            dfs(i,j-1,n,m,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int no_of_islands=0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    no_of_islands++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return no_of_islands;
    }
};