class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int j = 0;
        long long sum = 0;
        map<long, int>mp;
        mp[0]=-1;
        int n =nums.size();
        while(j < n){
            sum += nums[j];
            int rem = sum%k;
            if(mp.count(rem)){
                if(j-mp[rem]>=2)return true;
            }
            else mp[rem]=j;
            j++;
        }
        return false;
    }
};