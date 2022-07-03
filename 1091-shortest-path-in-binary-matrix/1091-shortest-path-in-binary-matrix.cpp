class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return -1;
        int col = grid[0].size();
        if (col == 0 ) return -1;
        if (grid[0][0] != 0 | grid[row-1][col-1] != 0) return -1;
        queue<pair<int, int>>q;
        q.push({0,0});
        int x[] = {0,0,-1,1,-1,1,-1,1};
        int y[] = {1,-1,0,0,-1,1,1,-1};
        while(!q.empty()){
            int siz = q.size();
            for(int i = 0 ; i < siz ; i++){
                pair<int, int> p = q.front();
                q.pop();
                int xx = p.first;
                int yy = p.second;
                if(xx == row - 1 && yy == col - 1)return 1+grid[xx][yy];
                for(int k = 0 ; k < 8 ; k++){
                    int nr = xx + x[k];
                    int nc = yy + y[k];
                    if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc]==0){
                        q.push({nr, nc});
                        grid[nr][nc] = grid[xx][yy]+1;
                    }
                }
            }
        }
        return -1;
    }
};