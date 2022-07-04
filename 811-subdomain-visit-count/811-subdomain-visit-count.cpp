class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int>mp;
        unordered_map<string, int>v;
        for(auto x : cpdomains){
            string s1 = "";
            string s2 = "";
            for(int i = 0; i < x.size() ; i++){
                if(x[i] == ' '){
                    s1 = s2;
                    s2 = "";
                }
                else
                    s2.push_back(x[i]);
            }
            v[s2] += stoi(s1);
        }
        for(auto x : v){
            string g = x.first;
            string temp;
            int n = g.size();
            string last = "";
            vector<string>domains;
            for(int i = 0; i < n ; i++){
                if(g[i] == '.'){
                    domains.push_back(last);
                    last = "";
                }
                else 
                    last.push_back(g[i]);
            }
            domains.push_back(last);
            string hehehaha = "";
            for(int i = -1+domains.size() ; i >= 0 ; i--){
                if(i == -1+domains.size())
                    hehehaha = domains[i];
                else 
                    hehehaha = domains[i] + "." + hehehaha;
                mp[hehehaha] += x.second;
            }
        }
        vector<string>ans;
        for(auto x : mp){
            string s = to_string(x.second) + " " + x.first;
            ans.push_back(s);
        }
        return ans;
    }
};