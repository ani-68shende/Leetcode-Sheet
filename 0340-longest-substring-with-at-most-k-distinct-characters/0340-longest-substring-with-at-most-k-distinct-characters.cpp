class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int i = 0, j =0;
        int n = s.size();
        int maxu = 0;
        unordered_map<int, int>mp;
        while(j < n){
            mp[s[j]]++;
            if(mp.size()>k){
                while(mp.size() > k){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            maxu = max(maxu, j-i+1);
            j++;
        }
        return maxu;
    }
};