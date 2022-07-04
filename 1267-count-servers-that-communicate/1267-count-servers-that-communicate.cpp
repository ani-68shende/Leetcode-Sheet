class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int tt = 0;
        for(auto x : grid){
            for(auto y : x){
                if(y == 1)
                    tt++;
            }
        }
        int x [] = {0,0,1,-1};
        int y [] = {1,-1,0,0};
        int count_alone =0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j =0 ; j < grid[0].size() ; j++){
                int flago = 0;
                if(grid[i][j] == 1){
                    for(int k = 0 ; k < grid[0].size() ; k++){
                        if(k!= j && grid[i][k] == 1){
                            flago++;
                            break;
                        }
                    }
                    for(int k = 0 ; k < grid.size() ; k++){
                        if(k!= i && grid[k][j] == 1){
                            flago++;
                            break;
                        }
                    }
                    if(flago == 0)count_alone++;
                }
            }
        }
        // cout << count_alone << endl;
        return tt - count_alone;
    }
};