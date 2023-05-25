//will do later
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0 or N >= K + W)
            return 1;
        
        vector<double> dp(N + 1, 0);
        dp[0] = 1;
        
        double wsum = 1.0;
        double res = 0;
        for(int i=1; i<N+1; i++) {
            dp[i] = wsum / double(W);
            if(i < K)
                wsum += dp[i];
            else
                res += dp[i];
            
            if(i-W >= 0)
                wsum -= dp[i-W];
        }
        
        return res;
    }
};