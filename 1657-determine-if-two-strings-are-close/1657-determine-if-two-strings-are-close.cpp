class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!= word2.size())return false;
        unordered_map<char, int>mp1, mp2;
        for(auto x : word1)mp1[x]++;
        for(auto y : word2)mp2[y]++;
        vector<int>v, vv;
        set<char>s1,s2;
        for(auto x : mp1)v.push_back(x.second),s1.insert(x.first);
        for(auto x : mp2)vv.push_back(x.second),s2.insert(x.first);
        if(s1!=s2)return false;
        sort(v.begin(), v.end());
        sort(vv.begin(), vv.end());
        return v == vv;
    }
};