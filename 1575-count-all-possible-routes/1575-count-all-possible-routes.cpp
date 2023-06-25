int mod = (int)1e9+7;
class Solution {
public:
    
    
    int dp[101][201];
    
    
    int func(int start, int finish, vector<int> & locations, int fuel){
        if(fuel < 0)return 0;
        if(dp[start][fuel]!=-1)return dp[start][fuel];
        int ans = 0;
        if(start == finish){
            ans++;
        }
        for(int i = 0 ; i < locations.size() ; i++){
            if(start != i and abs(locations[start]- locations[i]) <= fuel)
                ans = (ans + func(i, finish, locations, fuel-abs(locations[start]- locations[i])))%mod;
        }
        return dp[start][fuel] = ans;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        return func(start, finish, locations, fuel);
    }
};