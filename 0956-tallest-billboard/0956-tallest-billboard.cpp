class Solution {
public:
    
    
    int dp[21][10001];
    
        
    int func(int i, int sum, vector<int>& rods){
        if(i == rods.size()){
            if(sum == 0){
                return 0;
            }else{
                return -1e6;
            }
        }
        if(dp[i][sum+5000]!=-1)return dp[i][sum+5000];
        int nottake = func(i+1, sum, rods);
        int t1 = rods[i] + func(i+1, sum+rods[i], rods);
        int t2 = func(i+1, sum-rods[i], rods);
        return dp[i][sum+5000] = max({t1, t2, nottake});
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof(dp));
        return func(0, 0, rods);
    }
};