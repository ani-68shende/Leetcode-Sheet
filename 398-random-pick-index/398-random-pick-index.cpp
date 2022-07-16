class Solution {
public:
    unordered_map<int, vector<int>>mp;
    int idx = 0;
    Solution(vector<int>& nums) {
        for(auto x : nums){
            mp[x].push_back(idx);
            idx++;
        }
    }
    
    int pick(int target) {
        int idx = rand() % mp[target].size();
        return mp[target][idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */