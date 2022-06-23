class Solution {
public:
    string evaluate(string s, vector<vector<string>>& kw) {
        unordered_map<string, string>mp;
        for(auto x : kw){
            mp[x[0]] = x[1];
        }
        int n = s.size();
        string h;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                string z ="";
                if(i+1<n){
                    i++;
                }
                while(i < n && s[i]!=')'){
                    z.push_back(s[i]);
                    i++;
                }
                if(mp.find(z)!=mp.end())
                    h += mp[z];
                else
                    h += "?";
            }else{
                h.push_back(s[i]);
            }
        }
        return h;
    }
};