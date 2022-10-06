class Solution {
public:
    int helper(vector<int>& nums, int k){
        int i = 0 ;
        int j = 0 ;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        while(j < n){
            sum += nums[j];
            if(sum > k){
                while(i < n && sum != k){
                    sum -= nums[i];
                    i++;
                }
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        if(k==0)return helper(nums, k);
        return helper(nums, k) - helper(nums, k-1);
    }
};