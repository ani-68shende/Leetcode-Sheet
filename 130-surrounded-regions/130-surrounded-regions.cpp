class Solution {
public:
    void dfs2(int i, int j, int n, int m, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i>= n || j >= m || grid[i][j]=='X' || grid[i][j]=='U')return ;
        grid[i][j] = 'X';
        dfs2(i+1,j,n,m,grid);
        dfs2(i,j+1,n,m,grid);
        dfs2(i-1,j,n,m,grid);
        dfs2(i,j-1,n,m,grid);
    } 
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i>= n || j >= m || grid[i][j]=='X' || grid[i][j]=='U')return ;
        grid[i][j] = 'U';
        dfs(i+1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j-1,n,m,grid);
    } 
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if((i == n-1 && grid[i][j] == 'O') || (i == 0 && grid[i][j] == 'O') || (j == m-1 && grid[i][j] == 'O') || (j == 0 && grid[i][j] == 'O')){
                    dfs(i,j,n,m,grid);
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 'O'){
                    dfs2(i,j,n,m,grid);
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 'U'){
                    grid[i][j] = 'O';
                }
            }
        }
    }
};