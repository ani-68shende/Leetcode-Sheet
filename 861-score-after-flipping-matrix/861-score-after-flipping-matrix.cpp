class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        vector<vector<int>>dummy(grid);
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0]== 0){
                for(int j = 0 ; j < m ; j++){
                    if(grid[i][j]== 0)
                        grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        for(int k = 1 ; k < m ; k++){
            int zero = 0;
            int ones = 0;
            for(int i = 0; i < n ; i++){
                if(grid[i][k] == 0)zero++;
                else ones++;
            }
            if(ones < zero){
                for(int i = 0; i < n ; i++){
                    if(grid[i][k] == 0)grid[i][k]=1;
                    else grid[i][k] = 0;
                }
            }
        }
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            int power = 0;
            int k = 0;
            for(int j = m-1 ; j >= 0 ; j--){
                power+= grid[i][j]*(pow(2,k));
                k++;
            }
            sum += power;
        }
        return sum;
    }
};