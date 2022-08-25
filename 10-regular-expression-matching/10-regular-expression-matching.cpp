class Solution {
public:
    bool f(int n, int m, string s, string p, vector<vector<int>>& dp){
        // if both have reached the end then both have matched
        if(n < 0 && m < 0)return true;
        // the string is complete and pattern is remaining
        if(n < 0 && p[m] == '*'){
            return f(n, m-2, s, p, dp);
        }
        // if anyone of them is finished then we can't help
        if(n < 0 || m < 0){
            return false;
        }
        // matching case -> bonus
        if(dp[n][m]!=-1)return dp[n][m];
        if(s[n] == p[m]){
            return dp[n][m] = f(n-1, m-1, s, p, dp);
        }
        else{
            if(p[m]== '*'){
                if(s[n] == p[m-1] || p[m-1] == '.'){
                    return dp[n][m] = f(n-1, m, s, p, dp) || f(n, m-2, s, p, dp);
                }else{
                    return dp[n][m] = f(n, m-2, s, p, dp);
                }
            }else if(p[m] == '.'){
                return dp[n][m] = f(n-1, m-1, s, p, dp);
            }else{
                return dp[n][m] = false;
            }
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(21, vector<int>(31, -1));
        return f(n-1, m-1, s, p, dp);
    }
};