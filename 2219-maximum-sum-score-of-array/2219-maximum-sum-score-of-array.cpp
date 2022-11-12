class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long>pref(n), suff(n);
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i = 1 ; i < nums.size() ; i++){
            pref[i] = pref[i-1] + nums[i];
        }
        for(int i = nums.size()-2; i >= 0 ; i--){
            suff[i] = suff[i+1] + nums[i];
        }
        long long maxu = LLONG_MIN;
        for(int i = 0 ; i < n ;i+=1){
            maxu = max(maxu,max(suff[i],pref[i]));
        }
        return maxu;
    }
};