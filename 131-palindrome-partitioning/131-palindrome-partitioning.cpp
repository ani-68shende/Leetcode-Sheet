class Solution {
public:
    void helper(int idx, string s, vector<string> &z, vector<vector<string>>&ans){
        if(idx == s.size()){
            ans.push_back(z);
            return;
        }
        for(int i = idx; i < s.size() ; i++){
            if(palindrome(idx, i, s)){
                string h = s.substr(idx, i-idx+1);
                z.push_back(h);
                helper(i+1, s, z, ans);
                z.pop_back();
            }
        }
    }
    bool palindrome(int start, int end, string s){
        while(start <= end){
            if(s[start++]!=s[end--])return false;
            //start++;
            //end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> z;
        helper(0,s,z,ans);
        return ans;
    }
};