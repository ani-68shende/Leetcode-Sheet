class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int>x = {0, -1, 0, 1};
        vector<int>y = {1, 0, -1, 0};
        queue<pair<int, int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        int depth = -1;
        while(q.size() > 0){
            int nn = q.size();
            for(int k = 0 ; k < nn ; k++){
                pair<int, int> fr = q.front();
                q.pop();
                int x1 = fr.first;
                int y1 = fr.second;
                for(auto i = 0 ; i < 4 ; i++){
                    int xx = x1 + x[i];
                    int yy = y1 + y[i];
                    if(xx < 0 || yy < 0 || xx >= n || yy >= m || grid[xx][yy] == 0 || grid[xx][yy] == 2){
                        continue;
                    }
                    grid[xx][yy] = 2;
                    q.push({xx, yy});
                    count--;
                }
            }
            depth++;
        }
        if(count > 0){
            return -1;
        }
        if(depth == -1){
            return 0;
        }
        return depth;
    }
};