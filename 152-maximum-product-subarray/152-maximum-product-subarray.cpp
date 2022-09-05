class Solution {
public:
    // v2
    int maxProduct(vector<int>& nums) {
        int maxu = INT_MIN, n = nums.size(), prod = 1;
        for(int i = 0; i < n ; i++){
            prod *= nums[i];
            maxu = max(maxu, prod);
            if(prod == 0)prod = 1;
        }
        prod = 1;
        for(int i = n-1; i >= 0 ; i--){
            prod *= nums[i];
            maxu = max(maxu, prod);
            if(prod == 0)prod = 1;
        }
        return maxu;
    }
};