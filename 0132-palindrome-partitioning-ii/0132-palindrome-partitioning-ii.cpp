class Solution {
public:
    int dp[2022];
    bool checkPalin(string &s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    int f(int i, string&s){
        if(i >= s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int mini = s.size()+1;
        for(int ind = i ; ind < s.size() ; ind += 1){
            if(checkPalin(s,i,ind)){
                mini = min(mini, 1+f(ind+1,s));
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s)-1;
    }
};