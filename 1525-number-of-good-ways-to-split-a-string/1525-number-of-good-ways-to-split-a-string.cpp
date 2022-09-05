class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int>mp1, mp2; int ans = 0;
        for(auto x : s)mp2[x]++;
        for(auto x : s){
            mp1[x]++;
            mp2[x]--;
            if(mp2[x] == 0)mp2.erase(x);
            if(mp2.size() == mp1.size())ans++;
        }
        return ans;
    }
};