class Solution {
public:
    static bool cmp(pair<int, string> & a, pair<int, string> & b){
        if(a.second.size() == b.second.size()){
            return a.first < b.first;
        }
        return a.second.size() < b.second.size();
    }
    string arrangeWords(string text) {
        vector<string>v;
        string temp;
        for(int i(0) ; i < text.size() ;i++){
            if(text[i] == ' '){
                v.push_back(temp);
                temp = "";
                continue;
            }
            temp.push_back(tolower(text[i]));
        }
        v.push_back(temp);
        vector<pair<int ,string>>vv;
        for(int i =0 ; i < v.size() ; i++)vv.push_back({i, v[i]});
        sort(vv.begin(), vv.end(),cmp);
        string ans = "";
        for(auto c : vv)ans += c.second+" ";
        ans[0] = toupper(ans[0]);
        ans.pop_back();
        return ans;
    }
};