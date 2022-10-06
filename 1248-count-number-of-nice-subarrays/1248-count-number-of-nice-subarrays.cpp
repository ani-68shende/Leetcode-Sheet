class Solution {
public:
    // snippet from 930
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        //another no problem
        //convert it to zeroes and ones
        
        for(auto x = 0 ;x < nums.size() ; x++){
            nums[x] = ((nums[x]&1) == 1) ? 1 : 0;
        }
        return helper(nums, k) - helper(nums, k-1);
    }
};