class Solution {
public:
    bool isIsomorphic(string s, string p) {
        map<char, vector<int>>mp1, mp;
        int flag = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            mp[p[i]].push_back(i);
            mp1[s[i]].push_back(i);
            if(mp1.size() == mp.size() && mp[p[i]] == mp1[s[i]]){
                continue;
            }else{
                flag = 1;
                break;
            }
        }
        if(flag == 0)return true;
        return false;
    }
};