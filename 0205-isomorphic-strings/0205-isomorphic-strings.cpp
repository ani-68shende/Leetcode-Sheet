class Solution {
public:
    bool isIsomorphic(string s, string p) {
        map<char, vector<int>>ms, mp;
        int flag = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            mp[p[i]].push_back(i);
            ms[s[i]].push_back(i);
            if(ms.size() == mp.size() && mp[p[i]] == ms[s[i]]){
            }else{
                flag = 1;
                break;
            }
        }
        if(flag)return false;
        return true;
    }
};