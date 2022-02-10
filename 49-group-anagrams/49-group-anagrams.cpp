class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //just use normal sorting that you use else where and then you know what to do and what not to do
        vector<vector<string>>v;
        unordered_map<string, vector<string>>mp;
        for(auto x : strs){
            string h = x;
            sort(h.begin(), h.end());
            mp[h].push_back(x);
        }
        for(auto x : mp){
            
            v.push_back(x.second);
        }
        return v;
    }
};