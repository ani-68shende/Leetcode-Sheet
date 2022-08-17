class Solution {
public:
    // recursive
    int home_rob(int i, vector<int> &v, vector<int> & dp){
        if(i == 0)return v[i];
        if(i < 0)return 0;
        if(dp[i]!=-1)return dp[i];
        int notpick = 0 + home_rob(i-1, v, dp);
        int pick = v[i] + home_rob(i-2, v, dp);
        return dp[i] = max(pick, notpick);
    }
    int deleteAndEarn(vector<int>& nums) {
        // creation takes time so please wait
        int maxu = *max_element(nums.begin(), nums.end());
        vector<int>v(10001, 0), dp(10001, -1);
        for(int i(0) ; i < nums.size() ; i++){
            v[nums[i]] += nums[i];
        }
        // just adding maxu to improve tc
        return home_rob(maxu, v, dp);
    }
};