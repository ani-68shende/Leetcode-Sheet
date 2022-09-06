class Solution {
public:
    int dp[1<<16], N;
    int desired;
    bool f(int kk, vector<int>&nums, int mask, int k, int cur_sum){
        if(k == 0)return true;
        if(cur_sum == desired){
            return dp[mask] = f(0, nums, mask, k-1, 0);
        }
        if(dp[mask]!=-1)return dp[mask];
        for(int i = 0 ; i < N ; i++){
            if((mask&(1<<i)) || cur_sum + nums[i] > desired)continue;
            int pajwa_temp = mask;
            mask = mask|(1<<i);
            if(f(i+1, nums, mask, k, cur_sum+nums[i]))return dp[mask] = true;
            mask = pajwa_temp;
        }
        return dp[mask] = false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        N = n;
        memset(dp, -1, sizeof(dp));
        int sumu = 0;
        for(int i = 0 ; i < n ; i++)sumu += nums[i];
        if(sumu%k!=0 || n< k)return false;
        int mask = 0;
        desired = sumu/k;int cur_sum = 0;
        return f(0, nums, mask, k, cur_sum);
    }
};