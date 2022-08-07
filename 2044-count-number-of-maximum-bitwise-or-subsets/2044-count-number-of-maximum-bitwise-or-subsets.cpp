class Solution {
public:
    int f(vector<int>&nums,int idx,int currOr,int maxOr){
        if(idx < 0){
            return currOr == maxOr;
        }
        // you can excahnge the order of calling
        int notpick = f(nums,idx-1,currOr,maxOr);
        int pick = f(nums,idx-1,currOr|nums[idx],maxOr); 
        return pick + notpick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto num:nums){
            maxOr |= num;
        }
        return f(nums,nums.size()-1,0,maxOr);
    }
};