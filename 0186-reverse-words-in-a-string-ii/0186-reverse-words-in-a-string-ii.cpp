class Solution {
public:
    void reverseWords(vector<char>& s) {
        vector<string>ans;
        vector<char>vv;
        string temp = "";
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == ' '){
                ans.push_back(temp);
                temp = "";
            }
            else
            temp += s[i];
        }
        ans.push_back(temp);
        reverse(ans.begin(), ans.end());
        for(auto x : ans){
            for(int i = 0 ;i < x.size() ; i++){
                vv.push_back(x[i]);
            }
            vv.push_back(' ');
        }
        vv.pop_back();
        s=vv;
    }
};