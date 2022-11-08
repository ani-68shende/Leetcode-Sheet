class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long int, int>mp;
        long long sum = 0;
        int maxu = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            if(sum == k){
                maxu = max(maxu, i+1);
            }
            if(mp.count(sum-k)){
                maxu = max(maxu, i-mp[sum-k]);
                // cout << mp[sum-k] << " " << i << endl;
            }
            if(!mp.count(sum))mp[sum] = i;
        }
        return maxu;
    }
    int findMaxLength(vector<int>& nums) {
        vector<int>temp;
        for(auto x : nums)if(!x)temp.push_back(-1);else temp.push_back(x);
        return maxSubArrayLen(temp, 0);
    }
};