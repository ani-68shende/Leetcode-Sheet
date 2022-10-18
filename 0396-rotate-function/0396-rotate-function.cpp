class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int cur_sum = 0, su = 0;
        for(auto x : nums)su+=x;
        int n = nums.size();
        for(int i = 0 ; i < n ; i+=1){
            cur_sum += i*nums[i];
        }
        int maxu = cur_sum;
        for(int i = 0 ; i < n ;i++){
            cur_sum = cur_sum - (su-nums[i]) + nums[i]*(n-1);
            maxu = max(maxu, cur_sum);
        }
        return maxu;
    }
};