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
        //can shift the maxu up as well to avoid re-looping
        int maxu = 0;
        for(auto x : mp)maxu = max(maxu, x.second);
        return maxu;
    }
};