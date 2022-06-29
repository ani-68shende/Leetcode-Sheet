class Solution {
public:
    //memoization using shift of range .i.e i<0 -> i == 0
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
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return f(n, m, s, p, dp);
    }
};