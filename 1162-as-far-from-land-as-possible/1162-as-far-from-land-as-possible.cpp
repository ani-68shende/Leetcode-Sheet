class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int steps = 0;
        queue<pair<int, int>>q;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    q.push({ i - 1, j }), q.push({ i + 1, j }), q.push({ i, j - 1 }), q.push({ i, j + 1 });
                }
            }
        }
        while(!q.empty()){
            steps++;
            int siz = q.size();
            for(int i = 0 ; i < siz ; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size()){
                    if(grid[x][y] == 0){
                        grid[x][y] = steps;
                        q.push({x-1, y});
                        q.push({x+1, y});
                        q.push({x, y-1});
                        q.push({x, y+1});
                    }
                }
            }
        }
        return steps == 1 ? -1 : steps-1;
    }
};