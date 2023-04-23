class Solution {
public:
    int mod = (int)1e9+7;
    int dp[100001];
    int ff(int i, string &s, int &k){
        if(i >= s.size()){
            return 1;
        }
        if(dp[i]!=-1)return dp[i];
        int total_ways = 0;
        long long temp = 0;
        int n = s.size();
        bool flag = true;
        for(int j = i ; j < min(i+10, n) ; j++){
            temp = temp * 10 + ( s[j] - '0' );
            if(j+1 < s.size() and s[j+1] == '0'){
                while(j+1 < s.size() && s[j+1] == '0'){
                    if(temp > k){
                        flag = false;
                        break;
                    }
                    temp = temp * 10 + ( s[j+1] - '0' );
                    j++;
                }
            }
            if(flag == false){
                break;
            }
            if(temp <= k && temp >= 1){
                total_ways = (total_ways + ff(j+1, s, k))%mod;
            }else{
                break;
            }
        }
        return dp[i] = total_ways;
    }
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return ff(0, s, k);
    }
};