class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i(0), j(0);
        sort(nums.begin(), nums.end()); // god move
        int n = nums.size();
        long long maxu = 0;
        long long sum = 0;
        while(j < n){
            sum += nums[j];
            if(sum + k < 1LL*nums[j]*(j-i+1)){
                while(sum + k < 1LL*nums[j]*(j-i+1)){
                    sum -= nums[i];
                    i++;
                }
            }
            maxu = max(maxu, j-i+1+0LL);
            j++;
        }
        return maxu;
    }
};