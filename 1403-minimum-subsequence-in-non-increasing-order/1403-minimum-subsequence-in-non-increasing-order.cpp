class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int y = sum / 2;
        int limit = 0;
        vector<int>less_than_limit;
        for(int i = nums.size()-1; i >= 0 ; i--){
            if(y >= 0){
                less_than_limit.push_back(nums[i]);
                y -= nums[i];
            }
        }
        return less_than_limit;
    }
};