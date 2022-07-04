class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n, 0), suff(n, 0);
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i = 1 ; i < n ; i++){
            pref[i] = pref[i-1] + nums[i];
        }
        for(int i = n-2 ; i >= 0 ; i--){
            suff[i] = suff[i+1] + nums[i];
        }
        int idx = 0;
        for(int i = 0 ; i < n ; i++){
            if(pref[i] == suff[i]){
                return i;
            }
        }
        return -1;
    }
};