class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxu = 0;
        unordered_map<int, int>mp;
        for(auto x : nums){
            mp[x]++;
        }
        //if(mp.size() == 1)return 0;
        int max_ele = *max_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i]-nums[i-1] == 1)
            maxu = max(mp[nums[i]]+mp[nums[i-1]], maxu);
        }
        return maxu;
    }
};