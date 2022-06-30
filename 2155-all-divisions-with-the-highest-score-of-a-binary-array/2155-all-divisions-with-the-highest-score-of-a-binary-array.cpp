class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n, 0), suff(n, 0);
        vector<int>finala(n+1, 0);
        int c0 = 0, c1 = 0;
        for(int i = 0; i < n ; i++){
            if(nums[i] == 0)c0++;
            pref[i] = c0;
        }
        for(int i = n-1 ; i>= 0; i--){
            if(nums[i] == 1)c1++;
            suff[i] = c1;
        }
        finala[0] = suff[0];
        finala[n] = pref[n-1];
        for(int i = 0 ; i < n-1 ; i++){
            finala[i+1] = pref[i] + suff[i+1];
        }
        vector<int>ansres;
        int maxu = *max_element(finala.begin(), finala.end());
        for(int i = 0 ; i <= n; i++){
            if(finala[i]==maxu)ansres.push_back(i);
        }
        return ansres;
    }
};