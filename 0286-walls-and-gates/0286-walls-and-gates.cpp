class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        
        queue<pair<int, int>>q;
        vector<vector<int>>dir = {{0,-1},{-1,0},{0,1},{1,0}};
        for(auto i = 0 ; i < n ; i++){
            for(auto j = 0 ; j < m ; j++){
                if(rooms[i][j] == 0){
                    q.emplace(i,j);
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto d : dir){
                int new_x = x+d[0];
                int new_y = y+d[1];
                if(new_x < 0 || new_y < 0 || new_x >= n || new_y >= m || rooms[new_x][new_y] <= rooms[x][y]+1)continue;// op logic
                rooms[new_x][new_y] = rooms[x][y]+1;
                q.emplace(new_x, new_y);
            }
        }
    }
};