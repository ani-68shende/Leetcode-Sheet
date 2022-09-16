class Solution {
public://see prev to und better
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int pref=0;vector<int>ans(nums.size(), 0);
        int maxu = (1 << maximumBit)-1;
        for(int i = 0 ; i < nums.size() ; i++){
            pref^=nums[i];
            ans[nums.size()-i-1] = maxu ^ pref;
        }
        return ans;
    }
};