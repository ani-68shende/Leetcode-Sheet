class Solution {
public:
    int countTriplets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
cin.tie(NULL);
        int count = 0;
        int n = nums.size();
        unordered_map<int, int>mp;
        for(auto a : nums){
            for(auto b : nums){
                mp[a&b]++;
            }
        }
        for(auto x : mp){
            for(auto a: nums){
                if((a&x.first)==0)
                    count+=x.second;
            }
        }
        return count;
    }
};