class Solution {
public:
    //unique one god level
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
};