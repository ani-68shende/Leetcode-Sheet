class Solution {
public:
    int maximalSquare(vector<vector<char>>& ma) {
        int n = ma.size();
        int m = ma[0].size();
        int maxu = 1;
        int count = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(ma[i][j] == '0'){
                count++;
            }
        }
    }
    if(count == m*n){
        return 0;
    }
        // vector<vector<int>>dp(n, vector<int>(m));
        int dp[n][m];
        for(int i = n-1; i >=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                if(ma[i][j] == '0'){
                    dp[i][j] = 0;
                }
                else if(i == n-1 || j == m-1){
                    dp[i][j] = ma[i][j]-'0';
                }
                else{
                    dp[i][j]=1+min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
                    maxu = max(maxu, dp[i][j]);
                    }
                }
            }
        return maxu*maxu;
        }
};