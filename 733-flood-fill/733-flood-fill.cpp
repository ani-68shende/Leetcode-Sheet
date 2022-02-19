class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid,int oldc){
        if(i >=0 && j>=0 && i< n && j < m && grid[i][j]==oldc)return true;
        return false;
    }
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int oldc, int newColor){
        grid[i][j] = newColor;
        if(isValid(i+1,j,n,m,grid,oldc))
            dfs(i+1,j,n,m,grid,oldc,newColor);
        if(isValid(i,j+1,n,m,grid,oldc))
            dfs(i,j+1,n,m,grid,oldc,newColor);
        if(isValid(i-1,j,n,m,grid,oldc))
            dfs(i-1,j,n,m,grid,oldc,newColor);
        if(isValid(i,j-1,n,m,grid,oldc))
            dfs(i,j-1,n,m,grid,oldc,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        int n = grid.size();
        int m = grid[0].size();
        int oldc = grid[sr][sc];
        if(newColor == grid[sr][sc])return grid;
        dfs(sr,sc,n,m,grid,oldc,newColor);
        return grid;
    }
};