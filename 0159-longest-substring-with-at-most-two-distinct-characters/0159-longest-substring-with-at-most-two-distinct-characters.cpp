class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i = 0, j =0;
        int n = s.size();
        int maxu = 0;
        unordered_map<int, int>mp;
        while(j < n){
            mp[s[j]]++;
            if(mp.size()>2){
                while(mp.size() > 2){
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