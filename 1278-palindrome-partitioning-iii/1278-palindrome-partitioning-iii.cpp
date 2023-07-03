class Solution {
public:
    
    
    int dp[101][101];
    
    
    int n;
    int pal(int i, int j, string s){
        int count = 0;
        while(i <= j){
            if(s[i]!=s[j])count++;
            i++, j--;
        }
        return count;
    }
    int ff(int i, string s, int k){
        if(i >= n){
            return 1e4;
        }
        if(k == 0){
            return pal(i, n-1, s);
        }
        if(dp[i][k]!=-1)return dp[i][k];
        int ans = 1e4;
        for(int ind = i ; ind < n ; ind++){
            int cal = pal(i, ind, s);
            ans = min(ans, cal + ff(ind+1, s, k-1));
        }
        return dp[i][k] = ans;
    }
    int palindromePartition(string s, int k) {
        memset(dp, -1, sizeof(dp));
        n = s.size();
        k--;
        return ff(0, s, k);
    }
};