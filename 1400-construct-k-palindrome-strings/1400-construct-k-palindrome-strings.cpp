class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size())return false;
        unordered_map<char, int>mp;
        for(auto x : s){
            mp[x]++;
        }
        int count = 0;
        for(auto x : mp){
            if(x.second&1)count++;
        }
        if(count <= k)return true;
        else return false;
    }
};