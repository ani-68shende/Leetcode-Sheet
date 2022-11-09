class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long ssum = 0;
        int n = s.size();
        ssum += n;
        unordered_map<char, int>mp;
        for(auto x : s)mp[x]++;
        for(auto x : mp){
            ssum += 1LL*(x.second)*(x.second-1)/2;
        }
        return ssum;
    }
};