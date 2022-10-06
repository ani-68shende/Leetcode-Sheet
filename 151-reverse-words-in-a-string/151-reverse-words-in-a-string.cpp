class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string temp;
        int flag = 0;
        int i = 0;int n = s.size();
        while(i<n){
            if(s[i]!=' '){
                while(i < n && s[i]!=' '){
                    temp.push_back(s[i]);
                    i++;
                }
            }else{
                if(temp.size())
                    v.push_back(temp);
                temp = "";
                i++;
            }
        }
        if(temp.size())
            v.push_back(temp);
        // for(auto x : v)cout << x << " ";
        // cout << v.size() <<  endl;
        string ans;
        for(int i = v.size() - 1 ; i >= 0 ; i--)ans+=v[i]+" ";
        ans.pop_back();
        return ans;
    }
};