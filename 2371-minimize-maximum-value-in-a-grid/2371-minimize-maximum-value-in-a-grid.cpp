//superb logic to find the ordering and also ranks within each row and column

class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>v;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                v.push_back({grid[i][j], i, j});
            }
        }
        sort(v.begin(), v.end());
        vector<int>directions{1,0,-1,0,1};
        vector<int>row(n, 0), col(m, 0);
        for(int i = 0 ; i < m*n /*v.size() */ ; i++){
            int x = v[i][1];
            int y = v[i][2];
            int val = grid[x][y];
            grid[x][y] = max(row[x], col[y])+ 1;
            row[x] = max(grid[x][y], row[x]);
            col[y] = max(grid[x][y], col[y]);
        }
        return grid;
    }
};