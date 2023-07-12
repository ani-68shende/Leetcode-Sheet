//somehwhat unclear
class Solution {
public:
    int dp[101][101];
    int func(int i, int j, string&s){
        if(i == j){
            return 1;
        }
        int count = INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k = i ; k < j ; k++){
            count = min(count,  func(i, k,s) + func(k+1, j, s));
        }
        if(s[i] == s[j]){
            return dp[i][j] = count-1;
        }
        return dp[i][j] = count;
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return func(0, s.size()-1, s);
    }
};