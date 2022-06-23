class Solution {
public:
    //   Final Blow SPace OPTIMIZATION ------------------
    
    // int f(int i, int j, vector<vector<int>>& dp){
    //     if(i == 0 && j == 0)return 1;
    //     if(i < 0 || j < 0){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int top = f(i-1, j, dp);
    //     int left = f(i, j-1, dp);
    //     return dp[i][j] = top+left;
    // }
    int uniquePaths(int m, int n) {
        vector<int>prev(n, -1);
        vector<int>curr(n, -1);
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0){
                    curr[j] = 1;
                }
                else{
                    int top = 0, left = 0;
                    if(i >= 1)
                    top = prev[j];
                    if(j >= 1)
                    left = curr[j-1];
                    curr[j] = top+left;
                }
            }
            prev = curr;
        }
        // for(auto x : dp){
        //     for(auto y : x){
        //         cout << y << " ";
        //     }
        //     cout << "\n";
        // }
        return prev[n-1];
    }
};