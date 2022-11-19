class Solution {
public:
    int minimumKeypresses(string s) {
        unordered_map<char, int>mp;
        int counto = 0;
        int multiplier = 1;
        for(auto x : s)mp[x]++;
        vector<pair<int, char>>v;
        for(auto x : mp)v.push_back({x.second, x.first});
        sort(v.begin(),v.end(),greater<pair<int, char>>());
        int total = 0;
        int i = 0;
        int nn = v.size();
        int minu= 9;
        while(i < nn){
            while(i < min(minu,nn)){
                total += multiplier*v[i].first;
                i++;
            }
            minu *=2;
            multiplier++;
        }
        return total;
    }
};