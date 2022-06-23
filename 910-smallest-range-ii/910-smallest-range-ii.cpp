class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int maxu = -1e8;
        int mini  = 1e8;
        
        int n = nums.size();
        int res = nums[n-1] - nums[0];
        int left = nums[0]+k ; 
        int right = nums[n-1] -k;
        for(int i = 1 ; i < nums.size() ; i++){
            maxu = max(right, nums[i-1]+ k);
            mini = min(left, nums[i ] - k);
            res = min(res, maxu - mini);
        }
        return res;
    }
};