class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<long , long>mp;
        for(int i = 0 ; i < nums.size() ; i++){
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            mp[nums[i]-stoi(s)]++;
        }
        long long count= 0;
        long long mod = 1e9+7;
        for(auto x : mp)
            count = (count+(x.second*(x.second-1)/2)%mod)%mod;
        return count;
    }
};