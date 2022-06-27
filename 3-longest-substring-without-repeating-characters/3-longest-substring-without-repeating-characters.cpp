class Solution {
public:
    // 3 1695
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int j = 0;
        int n = s.size();
        int ans = 0;
        int i = 0;
        while(j < n){
            int d = j-i+1;
            mp[s[j]]++;
            if(mp.size() ==j-i+1){
                ans= max(ans, j-i+1);
            }
            if(mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
    
        return ans;
    }
};