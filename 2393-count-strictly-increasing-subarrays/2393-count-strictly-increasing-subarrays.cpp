class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 1;
        long long counto = 0;
        // int i = 1;
        long long level = 0;
        int prev = -1;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > prev){
                level += 1;
            }else{
                prev = -1;
                level = 1;
            }
            // cout << level << endl;
            counto += level;
            prev = nums[i];
        }
        return counto;
    }
};