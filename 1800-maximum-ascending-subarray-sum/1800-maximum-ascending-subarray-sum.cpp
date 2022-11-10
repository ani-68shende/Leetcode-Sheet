class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int prev = 0;
        long long maxu = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > prev){
                sum += nums[i];
            }else{
                sum = nums[i];
            }
            prev = nums[i];
            maxu = max(sum, maxu);
        }
        return maxu;
    }
};