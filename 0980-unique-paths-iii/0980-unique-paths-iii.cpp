class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int zc = 0;
        int sx = 0, sy = 0;
        for(int i =0 ;i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 0){
                    zc++;
                }
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
            }
        }
        return dfs(grid, sx, sy, zc);
    }
    int dfs(vector<vector<int>>& grid, int x, int y, int zc){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||grid[x][y] == -1){
            return 0;
        }
        if(grid[x][y] == 2){
            return zc == -1 ? 1 : 0;
        }
        grid[x][y] = -1;
        zc--;
        
        int total_paths = dfs(grid, x+1, y, zc) + dfs(grid, x, y+1, zc)+dfs(grid, x-1, y, zc) + dfs(grid, x, y-1, zc);
        
        grid[x][y] = 0;
        zc++;
        
        return total_paths;
    }
};