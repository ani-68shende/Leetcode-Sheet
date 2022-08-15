class Solution {
public:
    // % is the game changer --> (which separates this from medium level question) master 
    long long int f(long long int n, map<long long int, long long int> & dp){
        if(n <= 0){
            return 0;
        }
        if(n == 1)return 1;
        if(dp.find(n)!=dp.end())return dp[n];
        long long int ans1 = n%3 + 1 + f(n/3, dp);
        long long int ans2 = n%2 + 1 + f(n/2, dp);
        return dp[n]= min(ans1, ans2);
    }
    int minDays(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        map<long long int, long long int>dp;
        long long int num = n;
        return f(num, dp);
    }
};