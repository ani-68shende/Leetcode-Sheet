class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        unordered_map<int, int>mp;
        int maxu = 0;
        int sum = 0;
        int n = nums.size();
        while(j < n){
            if(mp.find(nums[j])!=mp.end()){
                int y = nums[j];
                while(i < n && nums[i] != y){
                    sum -= nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            } 
            sum += nums[j];
            mp[nums[j]]++;
            maxu = max(maxu, sum);
            j++;
        }
        return maxu;
    }
};