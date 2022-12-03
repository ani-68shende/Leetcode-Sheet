class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int count(0), i(0) , j(0);
        unordered_map<char, int>mp;
        int n = s.size();
        while(j < n){
            mp[s[j]]++;
            if(j-i+1==k){
                if(mp.size() == k){
                    count++;
                }
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return count;
    }
};