class Solution {
public:
    
    
    int dp[2001];
    
    
    int n;
    int p(int i, int j, string &s){
        while(i <= j){
            if(s[i] != s[j])return false;
            i++, j--;
        }
        return true;
    }
    int func(int i, string &s, int &k){
        if(i >= n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int count = 0;
        count = max(count, func(i+1, s, k));
        for(int ind = i+k-1 ; ind < n; ind++){
            if(p(i, ind, s)){
                count = max(count, 1+func(ind+1, s, k));
            }
        }
        return dp[i] = count;
    }
    int maxPalindromes(string s, int k) {
        n = s.size();
        if(k == 1)return n;
        memset(dp, -1, sizeof(dp));
        return func(0, s, k);
    }
};