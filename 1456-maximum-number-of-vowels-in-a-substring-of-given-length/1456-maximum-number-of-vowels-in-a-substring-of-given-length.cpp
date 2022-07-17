class Solution {
public:
    int maxVowels(string s, int k) {
        int maxu = 0;
        unordered_map<char, int>mp;
        mp['a']++;
        mp['e']++;
        mp['i']++;
        mp['o']++;
        mp['u']++;
        int i = 0, j = 0;
        int n = s.size();
        int res = 0;
        int count = 0;
        while(j < n){
            if(mp.find(s[j])!=mp.end()){
                count++;
            }
            if(j-i+1 == k){
                res = max(res, count);
                if(mp.find(s[i]) != mp.end()){
                    count--;
                }
                i++;
            }
            j++;
        }
        return res;
    }
};