class Solution {
public:
    int n;
    int dp[104][1005][6];
    int f(int i, vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons){
        
        if(i == n){
            return 0;
        }
        
        if(dp[i][maxAmount][maxCoupons]!=-1)return dp[i][maxAmount][maxCoupons];
        
        int take = 0, nottake = 0, coupons = 0;
        // kab le sakta .. jab paisa jyada ho (jo ki mere pass nahi hai T-T)
        
        
        
        if(maxAmount - price[i]/2 >= 0 && maxCoupons>0){
            coupons = tastiness[i] + f(i+1, price, tastiness, maxAmount - price[i]/2, maxCoupons-1);
        }
        
        
        
        
        if(maxAmount - price[i] >= 0){
            take = tastiness[i] + f(i+1, price, tastiness, maxAmount - price[i], maxCoupons);
        }
        
        
        
        nottake = 0 + f(i+1, price, tastiness, maxAmount, maxCoupons);
        
        
        
        // cout << take << " " << nottake << " " << coupons << endl;
        return dp[i][maxAmount][maxCoupons] = max({take, nottake, coupons});
    }
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        n = price.size();
        memset(dp,-1,sizeof(dp));
        return f(0, price, tastiness, maxAmount, maxCoupons);
    }
};