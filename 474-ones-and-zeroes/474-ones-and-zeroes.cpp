class Solution {
public:
    // memoization
    int f(int i, vector<string>& s, int m, int n, vector<vector<vector<int>>> & dp){
        //base cases
        if(i < 0 || m < 0 || n < 0)return 0;
        //count zeros and ones
        
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        
        int count0 = 0, count1 = 0;
        for(auto x : s[i]){
            if(x == '0')
                count0++;
            else
                count1++;
        }
        
        // if count0 <= m && count1 <= n then we have 2 options :
            // a) do not add it
            // b) add it 
        if(count0 <= m && count1 <= n){
            // a) do not add it .i.e count is not added
            int notTake = 0 + f(i-1, s, m, n, dp);
            int take = 1 + f(i-1, s, m-count0, n-count1, dp);
            return dp[i][m][n] = max(take, notTake);
        }
        
        
        // if the condition count0 <= m && count1 <= n holds false then we dont have any option but to skip it :
        else 
            return dp[i][m][n] = f(i-1, s, m, n, dp);        
    }
    int findMaxForm(vector<string>& s, int m, int n) {
        int siz = s.size();
        vector<vector<vector<int>>>dp(siz, vector<vector<int>>(m+1, vector<int>(n+1 , -1)));
        return f(siz-1, s, m, n, dp);
    }
};