class Solution {
public:
    
    // prajwa hai toh possible hai
    
    int n = 0;
    long long int M = 1e9+7;
    int f(int i, int mask, vector<int>adj[], vector<vector<long long int>> & dp){
        if(__builtin_popcount(mask) == n)return 1;
        if(i >= 41)return 0;
            
        if(dp[i][mask]!=-1)return dp[i][mask];
        
        long long int count = 0;
        for(auto x : adj[i]){
            if((mask & (1 << x)) == 0){
                int t = mask | (1 << x);
                count = (count + f(i+1, t, adj, dp))%M;
            }
        }
        count = (count + f(i+1, mask, adj, dp))% M;
        return dp[i][mask] = count;
    }
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        vector<int> adj[45];
        for(int i = 0 ; i < hats.size() ; i++){
            for(auto x : hats[i]){
                adj[x].push_back(i);
            }
        }
        // cout << M << endl;
        vector<vector<long long int>>dp(42, vector<long long int>((1 << 11), -1));
        return f(0, 0, adj, dp);
    }
};