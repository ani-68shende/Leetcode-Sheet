class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int>mp;
        int i = 0;
        int j = 0;
        int k = 10;
        int n = s.size();
        string str = "";
        while(j < n){
            str+=s[j];
            if(j-i+1==k){
                mp[str]++;
                str.erase(str.begin());
                i++;
            }
            j++;
        }
        vector<string>ss;
        for(auto x : mp)if(x.second>1)ss.push_back(x.first);
        return ss;
    }
};