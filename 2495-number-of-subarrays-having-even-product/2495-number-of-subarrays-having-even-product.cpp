//too op... other way round is to check for all odd subarrays and then do n*(n+1)/2 - subarrys of consecutive odd lengths sum
class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        long long val = 0;
        for(int i = 0 ;i < n ; i++){
            if(nums[i]%2==0){
                val = i+1;
            }
            ans += val;
        }
        return ans;
    }
};