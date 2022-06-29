class Solution {
public:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        // 4 cases- 3 to be handled as base cases
        if(i < 0 && j < 0)return true;
        if(i < 0 && j >= 0)return false;
        if(i >= 0 && j < 0){
            for(int ii = 0 ; ii <= i ;ii++){
                if(p[ii]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(p[i] == s[j] || p[i] == '?'){
            return f(i-1, j-1, s, p, dp);
        }
        else if(p[i] == '*'){
            return dp[i][j] = f(i-1, j, s, p, dp) | f(i, j-1, s, p, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s, p, dp);
    }
};