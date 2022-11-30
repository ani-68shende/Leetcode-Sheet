class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int>s;
        unordered_map<int, int>mp;
        for(auto y : arr){
            s.insert(y);
            mp[y]++;
        }
        set<int>s2;
        for(auto x : mp)s2.insert(x.second);
        return s2.size() == s.size();
    }
};