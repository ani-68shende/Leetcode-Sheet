class Solution {
public:
    int f(int i, string & s, int &n, vector<int>& dp){
        
        if(i >= n)return 1;
        if(i < n && s[i] == '0')return 0;
        
        if(dp[i] != -1)return dp[i];
        
        int take_one = 0;
        if(s[i] != '0')
            take_one = f(i+1, s, n, dp);
        
        int take_two = 0;
        if(i+1<n && ((s[i] == '1' && s[i + 1] <= '9') || (s[i]  == '2' && s[i + 1] <= '6')))
            take_two = f(i+2, s, n, dp);
        
        return dp[i] =  take_two + take_one;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n, -1);
        return f(0, s, n, dp);
    }
};