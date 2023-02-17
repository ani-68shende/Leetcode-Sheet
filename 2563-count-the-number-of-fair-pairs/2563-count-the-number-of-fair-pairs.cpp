class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        sort(nums.begin(),nums.end());

        long long ans=0;

        int size=nums.size();

        for(int i=0;i<size;i++)
        {

            int index=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            int other=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();

            ans+=0LL+other-index;

        }

        return ans;
        
    }
};