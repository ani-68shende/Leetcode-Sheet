class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int i = 0, j =0;
        unordered_map<int, int>mp;
        int n = nums.size();
        vector<int>ans;
        while(j < n){
            mp[nums[j]]++;
            if(j-i+1 == k){
                ans.push_back(mp.size());
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};