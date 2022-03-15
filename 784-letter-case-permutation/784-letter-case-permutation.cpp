class Solution {
public:
    void cases(int idx, string s, string &z, set<string>&ans){
        if(idx == s.size()){
            ans.insert(z);
            return;
        }
        char ch = s[idx];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
        {
            if(ch>='A' && ch<='Z')
                ch=ch+32;
            else if(ch>='a' && ch<='z')
                ch=ch-32;
        }
        z.push_back(ch);
        cases(idx+1, s, z, ans);
        z.pop_back();
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
        {
            if(ch>='A' && ch<='Z')
                ch=ch+32;
            else if(ch>='a' && ch<='z')
                ch=ch-32;
        }
        z.push_back(ch);
        cases(idx+1, s, z, ans);
        z.pop_back();
    }
    vector<string> letterCasePermutation(string s) {
        set<string>ans;
        string z;
        cases(0, s, z, ans);
        vector<string>res;
        for(auto x : ans){
            res.push_back(x);
        }
        return res;
    }
};