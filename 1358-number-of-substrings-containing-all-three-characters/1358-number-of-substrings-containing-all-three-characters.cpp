class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0;
        int res = 0;
        int n = s.size();
        unordered_map<char, int>mp;
        while(j < n){
            mp[s[j]]++;
            while(mp['a']>0 && mp['b'] > 0 && mp['c']>0){
                res++;
                res += (n-j-1);
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return res;
    }
};