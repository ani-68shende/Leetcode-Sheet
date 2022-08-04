class Solution {
public:
    int f(int i, int j, int n, int m, vector<vector<int>> & grid){
        if(i == m){
            return j;
        }
        //if(j < 0 || j >= n)return -1;
        if(grid[i][j] == 1){
            if(j+1<n && grid[i][j+1] == 1){
                return f(i+1,j+1, n, m, grid);
            }
        }
        if(grid[i][j] == -1){
            if(j-1>=0 && grid[i][j-1] == -1){
                return f(i+1,j-1, n, m, grid);
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>v;
        for(int i = 0 ; i < n ; i++){
            v.push_back(f(0, i, n, m, grid));
        }
        return v;
    }
};