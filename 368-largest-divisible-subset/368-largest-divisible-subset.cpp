class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = 0;
        int n = nums.size();
        vector<int>cc(n, 1);
        vector<int>ans;
        int maxu = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i; j++){
                if(nums[i]%nums[j]==0){
                    cc[i] = max(cc[i], 1 + cc[j]);
                }
            }
            if(maxu < cc[i]){
                maxu = cc[i];
                idx = i;
            }
        }
        int prev = nums[idx];
        while(idx>=0){
            if(cc[idx] == maxu && prev%nums[idx] == 0){
                prev = nums[idx];
                ans.push_back(prev);
                maxu-=1;
            }
            idx--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};