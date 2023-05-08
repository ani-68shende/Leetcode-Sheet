class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int>mp;
        for(int i = 0 ; i < n ;i++){
            if(mp.find(arr[i]-difference)!=mp.end()){
                mp[arr[i]]=1 + mp[arr[i]-difference];
            }else{
                mp[arr[i]]=1;
            }
        }
        //https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/?envType=study-plan-v2&id=dynamic-programming
        //can shift the maxu up as well to avoid re-looping
        int maxu = 0;
        for(auto x : mp)maxu = max(maxu, x.second);
        return maxu;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int maxu = 0;
        for(int i = -maxi+mini ; i <= maxi-mini ; i++){
            maxu = max(maxu, longestSubsequence(nums, i));
        }return maxu;
    }
};