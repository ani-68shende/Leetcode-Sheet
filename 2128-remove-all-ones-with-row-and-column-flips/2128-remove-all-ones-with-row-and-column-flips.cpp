class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < m ; i++){ //col wise iteration
            if(1 == grid[0][i]){
                for(int j = 0 ; j < n ; j++){
                    grid[j][i] = !grid[j][i]; //be careful with j and i
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            int sum = 0;
            for(int j = 0 ; j < m ; j++){
                sum += grid[i][j];
            }
            //he did not even face the first row's punch
            if(sum != 0 && sum!=m){
                return false;
            }
        }
        return true;
    }
};