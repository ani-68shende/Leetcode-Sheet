class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>>q;
        int x[] = {0,0,-1,1};
        int y[] = {1,-1,0,0};
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }else{
                    grid[i][j] = 1e8;
                }
            }
        }
        while(!q.empty()){
            int siz = q.size();
            for(int i = 0 ; i < siz ; i++){
                pair<int, int> p = q.front();
                q.pop();
                int xx = p.first;
                int yy = p.second;
                for(int k = 0 ; k < 4 ; k++){
                    int nr = xx + x[k];
                    int nc = yy + y[k];
                    if(nr < 0 || nc < 0 || nr >= row || nc >= col || grid[nr][nc]<=1+grid[xx][yy]){
                        continue;
                    }
                    else{
                        q.push({nr, nc});
                        grid[nr][nc] = 1+grid[xx][yy];
                    }
                }
            }
        }
        return grid;
    }
};