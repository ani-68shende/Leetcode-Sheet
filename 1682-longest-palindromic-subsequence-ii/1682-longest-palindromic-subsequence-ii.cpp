class Solution {
public:
    int dp[251][251][30];
    int f(int i, int j, char prev,string & s){
        if(i >= j)return 0;
        if(s[i] == prev)return f(i+1,j,prev,s);
        if(s[j] == prev)return f(i,j-1,prev,s);
        if(dp[i][j][prev-'a']!=-1)return dp[i][j][prev-'a'];
        if(s[i] == s[j]){
            //length to be added
            return 2+f(i+1,j-1,s[i],s);
        }
        return dp[i][j][prev-'a'] = max(f(i+1,j,prev,s),f(i,j-1,prev,s));
    }
    int longestPalindromeSubseq(string s) {
        int i = 0;
        int j = s.size()-1;
        memset(dp,-1,sizeof(dp));
        return f(i,j,'{',s);
    }
};