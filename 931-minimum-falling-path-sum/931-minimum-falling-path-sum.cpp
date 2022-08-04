class Solution {
public:
    bool isvalid(int j, int m, int n){
        if(j < 0 || j>= n)return false;
        return true;
    }
    int f(int i, int j, int m, int n, vector<vector<int>> & matrix, vector<vector<int>> & dp){
        if(i == m-1)return matrix[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int mini2 = INT_MAX;
        for(int k = -1 ; k < 2 ; k++){
            if(isvalid(j+k, m, n)){
                mini2 = min(f(i+1, j+k, m, n, matrix, dp)+matrix[i][j], mini2);
            }
        }
        dp[i][j] = mini2;
        return mini2;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i = 0 ; i < n ; i++){
            mini = min(mini, f(0, i, m, n,  matrix, dp));
        }
        return mini;
    }
};