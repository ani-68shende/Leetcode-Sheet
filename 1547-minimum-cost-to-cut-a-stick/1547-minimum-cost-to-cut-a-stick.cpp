class Solution {
public:
    long long int f(int i, int j, vector<int>& values, vector<vector<int>> & dp){
        if(i > j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long int mini = 1e7;
        for(int k = i ; k <= j ; k++){
            mini = min(mini, values[j+1]-values[i-1]
                       + f(i, k-1, values, dp) 
                       + f(k+1, j, values, dp));
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& values) {
        values.push_back(0);
        values.push_back(n);
        sort(values.begin(), values.end());
        vector<vector<int>>dp(values.size(), vector<int>(values.size(), -1));
        return f(1, values.size()-2, values, dp);
    }
};