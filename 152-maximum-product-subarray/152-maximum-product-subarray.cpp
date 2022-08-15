class Solution {
public:
    // v2
    int maxProduct(vector<int>& nums) {
        int maxu = 0;
        int n = nums.size();
        if(n == 1)return nums[0];
        long long maxuu = INT_MIN;
        long long int mul = 1;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                mul = 1;
                maxuu = max(maxuu, 0*1LL);
                continue;
            }
            mul *= nums[i];
            maxuu = max(maxuu, mul);
        }
        reverse(nums.begin(),nums.end());
        mul = 1;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                mul = 1;
                maxuu = max(maxuu, 0*1LL);
                continue;
            }
            mul *= nums[i];
            maxuu = max(maxuu, mul);
        }
        return maxuu;
    }
};