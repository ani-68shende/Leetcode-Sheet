class Solution {
public:
    int n, m;
    vector<int>dir{-1,0,1,0,-1};
    int mall(int i, int j, vector<vector<int>> &grid){
        if(i < 0 || j < 0 || i >= n || j >= m)return 0;
        if(grid[i][j] == 0)return 0;
        int sum = grid[i][j];
        grid[i][j] = 0;
        int u = 0;
        for(int k = 0 ; k < 4 ; k++){
            u = max(u, mall(i+dir[k], j+dir[k+1], grid));
        }
        grid[i][j] = sum;
        return sum+u; 
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int maxu = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==0)continue;
                maxu = max(maxu, mall(i,j,grid));
                // break;
            }
        }
        return maxu;
    }
};