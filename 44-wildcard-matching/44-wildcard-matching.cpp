class Solution {
public:
    //tabulation using shift of range .i.e i<0 -> i == 0
    // n-1 -> n
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        // 4 cases- 3 to be handled as base cases
        if(i == 0 && j == 0)return true;
        if(i == 0 && j > 0)return false;
        if(i > 0 && j == 0){
            for(int ii = 1 ; ii <= i ;ii++){
                if(p[ii-1]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(p[i-1] == s[j-1] || p[i-1] == '?'){
            return f(i-1, j-1, s, p, dp);
        }
        else if(p[i-1] == '*'){
            return dp[i][j] = f(i-1, j, s, p, dp) | f(i, j-1, s, p, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1, -1));
        // return f(n, m, s, p, dp);
        dp[0][0] = true;
        for(int j = 1 ; j <= m ; j++){
            dp[0][j] = false;
        }
        //tricky part starts
        for(int i = 1 ; i <= n ; i++){
            bool flag = true;
            for(int ii = 1 ; ii <= i ;ii++){
                if(p[ii-1]!='*'){
                    flag = false;
                }
            }
            dp[i][0] = flag;
        }
        //tricky part ends
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                //imp step of adding else
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};