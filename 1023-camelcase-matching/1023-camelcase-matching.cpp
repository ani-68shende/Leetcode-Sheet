class Solution {
public:
    //code xplainerxx
    bool helper(int i, int j, string s, string p){
        if(i == s.size() && j == p.size()){
            return true;
        }
        if(s[i] == p[j]){
            return helper(i+1,j+1,s,p);
        }else{
            if(s[i]>='a' && s[i]<='z'){
                return helper(i+1,j,s,p);
            }else{
                return false;
            }
        }
        return false;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        for(auto x : queries){
            if(helper(0,0,x,pattern))ans.push_back(1);else ans.push_back(0);
        }
        return ans;
    }
};