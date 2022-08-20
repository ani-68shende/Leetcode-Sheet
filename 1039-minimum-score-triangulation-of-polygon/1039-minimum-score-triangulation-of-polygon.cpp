class Solution {
public:
    int f(int i, int j, vector<int>& values, vector<vector<int>> & dp){
        if(i == j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = 1e9;
        for(int k = i ; k < j ; k++){
            mini = min(mini, values[i-1]*values[k]*values[j] 
                       + f(i, k, values, dp) 
                       + f(k+1, j, values, dp));
        }
        return dp[i][j] = mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return f(1, n-1, values, dp);
    }
};