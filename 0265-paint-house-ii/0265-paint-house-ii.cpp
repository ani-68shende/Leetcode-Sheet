class Solution {
public:
    int n;
    int m;
    int dp[105][22];
    int f(int i, vector<vector<int>> & costs, int prev){
        if(i >= n){
            return 0;
        }
        if(dp[i][prev]!=-1)return dp[i][prev];
        int minicost = INT_MAX;
        for(int k = 0; k < m ; k++){
            if(k != prev){
                int sum = costs[i][k] + f(i+1, costs, k);
                minicost = min(minicost, sum);
            }
        }
        return dp[i][prev] = minicost;
    }
    int minCostII(vector<vector<int>>& costs) {
        n = costs.size();
        m = costs[0].size();
        memset(dp, -1, sizeof(dp));
        int prev = 21; //for storing in dp .. otherwise -1;
        int sum = 0;
        return f(0, costs, prev);
    }
};