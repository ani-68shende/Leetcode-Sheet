class Solution {
public:
    
    //memoizaytion - making two arrays so that we can handle the adjacent condition of 1 & n-1 (first and last)
    
    int f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind == 0){
            return nums[ind];
        }
        if(ind < 0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int notTake = 0 + f(ind-1, nums, dp);
        int take = nums[ind] + f(ind-2, nums, dp);
        return dp[ind] = max(notTake, take);
    }
    int rob(vector<int>& nums) {
        vector<int>n1,n2;
        if(nums.size() == 1)return nums[0];
        vector<int> dp1(nums.size(), -1), dp2(nums.size(), -1);
        for(int i = 0 ; i < nums.size()-1; i++){
            n1.push_back(nums[i]);
        }
        for(int i = 1 ; i < nums.size(); i++){
            n2.push_back(nums[i]);
        }
        int sum1 = f(n1.size()-1, n1, dp1);
        int sum2 = f(n2.size()-1, n2, dp2);
        return max(sum1, sum2);
    }
};