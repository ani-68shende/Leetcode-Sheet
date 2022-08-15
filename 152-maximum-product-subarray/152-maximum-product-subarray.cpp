class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxu = 0;
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int>pref;
        vector<int>suff;
        long long int mul = nums[0];
        if(mul == 0) mul = 1;
        pref.push_back(nums[0]);
        for(int i = 1 ; i < n ; i++){
            if(nums[i] == 0){
                pref.push_back(nums[i]);
                mul = 1;
                continue;
            }
            mul *= nums[i];
            pref.push_back(mul);
        }
        reverse(nums.begin(),nums.end());
        suff.push_back(nums[0]);
        mul = nums[0];
        if(mul == 0)mul = 1;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] == 0){
                suff.push_back(nums[i]);
                mul = 1;
                continue;
            }
            mul *= nums[i];
            suff.push_back(mul);
        }
        long long maxuu = INT_MIN;
        for(auto x : pref){
            // cout << x << " ";
            maxuu = max(maxuu, x*1LL);
        }
        for(auto x : suff){
            // cout << x << " ";
            maxuu = max(maxuu, x*1LL);
        }
        return maxuu;
    }
};