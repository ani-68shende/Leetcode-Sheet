class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n(nums.size());
        vector<int> pref(nums);
        for(int i = 1 ; i < n ; i++){
            pref[i]^=pref[i-1];
        }
        vector<int>ans;
        int maxu = (1 << maximumBit)-1;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(maxu ^ pref[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};