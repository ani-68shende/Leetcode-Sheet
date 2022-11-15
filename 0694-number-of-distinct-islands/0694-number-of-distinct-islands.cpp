class Solution {
public:
    int n;
  int m;
    bool valid(int i, int j, vector<vector<int>>& grid){
        if(i >=0 && j >=0 && j < m && i < n && grid[i][j]){
            return true;
        }
        return false;
    }
    int ini, inj;
    void dfs(int i, int j, string &h, vector<vector<int>>& grid){
        if(i < 0 && j < 0 && i >= n && j>= m){
            return ;
        }
        h+=(to_string(i-ini));
        h+=(to_string(j-inj));
        grid[i][j] = 0;
        if(valid(i+1, j, grid))dfs(i+1, j, h, grid);
        if(valid(i-1, j, grid))dfs(i-1, j, h, grid);
        if(valid(i, j+1, grid))dfs(i, j+1, h, grid);
        if(valid(i, j-1, grid))dfs(i, j-1, h, grid);
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        // code here
        n = grid.size();
        m = grid[0].size();
        int components = 0;
        set<string>s;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    string h;
                    ini = i, inj = j;
                    dfs(i, j, h, grid);
                    s.insert(h);
                }
            }
        }
        return s.size();
    }
};