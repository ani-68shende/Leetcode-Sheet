class Solution {
public:
    bool canConstruct(string rN, string m) {
        unordered_map<char, int>mp, mp2;
        for(auto x : rN){
            mp[x]++;
        }
        for(auto x : m){
            mp2[x]++;
        }
        bool flagu = false;
        for(auto x : rN){
            if(mp2[x]<mp[x])return false;
        }
        return true;
    }
};