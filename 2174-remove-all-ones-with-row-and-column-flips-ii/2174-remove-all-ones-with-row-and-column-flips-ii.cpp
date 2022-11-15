class Solution {
public:
    //see its first part
    int n, m;
    int removeOnes(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int counto = INT_MAX;
        vector<vector<int>> temp;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(grid[i][j] == 1){
                    temp = grid;
                    for(int k = 0 ; k < n ; k++){
                        grid[k][j] = 0;
                    }
                    for(int k = 0 ; k < m ; k++){
                        grid[i][k] = 0;
                    }
                    counto = min(counto, 1+removeOnes(grid));
                    grid = temp;
                }
            }
        }
        return counto == INT_MAX ? 0 : counto;
    }
};