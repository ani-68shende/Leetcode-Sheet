class Solution {
public:
    // the real game was of constraints
    vector<int> findSubstring(string s, vector<string>& words) {
        int siz = (words[0].size())*(words.size());
        int len = words[0].size();
        if(s.size() < siz)return {};
        unordered_map<string, int>mp, mp1;
        for(auto x : words)mp[x]++;
        vector<int> gold;
        for(int i(0) ; i <= s.size()-siz ; i++){
            mp1 = mp;
            for(int j = 0 ; j < words.size() ; j++){
                string ss = s.substr(i+j*len, len);
                if(mp1.find(ss)!=mp1.end()){
                    mp1[ss]--;
                    if(mp1[ss] == 0)mp1.erase(ss);
                    if(mp1.size() == 0){
                        gold.push_back(i);
                        break;
                    }
                }else{
                    break;
                }
            }
        }
        return gold;
    }
};