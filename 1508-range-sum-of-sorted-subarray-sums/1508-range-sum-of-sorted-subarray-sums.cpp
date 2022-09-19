class Solution {
public:
    long long mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long sum= 0;
        vector<long long>ans;
        for(auto i = 0 ; i < n ; i++){
            long long cnt = 0;
            for(int j(i) ; j < n ; j++){
                cnt += nums[j];
                ans.push_back(cnt);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i(left-1) ; i <= -1+right ;i++)sum = (sum+ans[i])%mod;
        return sum;
    }
};