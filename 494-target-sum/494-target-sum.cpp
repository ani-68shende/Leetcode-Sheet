class Solution {
public:
    // a kind of tricky edge cases
    // did large chnages in index base case and then also changed the "take" case
    int f(int ind, vector<int>& nums, int sum, int target){
        if(ind < 0 && target == sum)return 1;
        if(ind < 0)
             return 0;
        int notTake = f(ind-1, nums, sum+nums[ind], target);
        int take = f(ind-1, nums, sum-nums[ind], target);
        return notTake+take;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        if(nums.size() == 1 &&  abs(nums[0]) == abs(target))return 1;
        return f(nums.size()-1, nums, sum, target);
    }
};