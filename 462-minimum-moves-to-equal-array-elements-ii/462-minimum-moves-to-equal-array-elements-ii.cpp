class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = nums[n/2];
        int total = 0;
        for(auto x : nums){
            total += abs(mid-x);
        }
        return total;
    }
};