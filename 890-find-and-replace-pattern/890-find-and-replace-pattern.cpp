class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string>v;
        int n = p.size();
        for(auto x : words){
            map<char, vector<int>>mp1, mp;
            int flag = 0;
            for(int i = 0 ; i < n ; i++){
                mp[p[i]].push_back(i);
                mp1[x[i]].push_back(i);
                if(mp1.size() == mp.size() && mp[p[i]] == mp1[x[i]]){
                    continue;
                }else{
                    flag = 1;
                    break;
                }
                
            }
            if(flag == 0){
                v.push_back(x);
            }
            // vector<int>b;
            // for(auto d : mp1){
            //     b.push_back(d.second);
            // }
            // //sort(b.begin(), b.end());
            // int flag = 0;
            // if(mp1.size() == mp.size()){
            //     for(int i = 0 ; i < mp1.size() ; i++){
            //         if(b[i] != dummy[i])flag = 1;
            //     }
            //     if(flag == 0)v.push_back(x);
            // }
        }
        return v;
    }
};