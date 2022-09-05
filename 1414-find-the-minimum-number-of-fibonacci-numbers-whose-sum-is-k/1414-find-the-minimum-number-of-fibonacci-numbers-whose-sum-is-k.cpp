class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        long long sum= 0;
        vector<int>dp;
        dp.push_back(1);
        dp.push_back(1);
        for(int i = 1 ; sum <= 1e9 ; i++){
            sum = dp[i-1]+dp[i];
            dp.push_back(sum);
        }
        int count =0 ;
        int d = k;
        int i = dp.size()-2;
        while(d!=0){
            while(d-dp[i]>=0){
                count++;
                d-=dp[i];
            }
            i--;
        }
        return count;
    }
};