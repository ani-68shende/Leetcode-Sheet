class Solution {
public:
    bool check(string s){
        stack<char>st;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(st.size()>0){
                    if(st.top() == '(')
                        st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.size() != 0)return false;
        return true;
    }
    void helper(int idx, vector<string>&ans, string &s, int n){
        if(idx == n){
            if(check(s))ans.push_back(s);
            return;
        }
        s.push_back('(');
        helper(idx+1, ans, s, n);
        s.pop_back();
        s.push_back(')');
        helper(idx+1, ans, s, n);
        s.pop_back();
    }    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int idx = 0;
        string s;
        helper(idx, ans, s, n*2);
        return ans;
    }
};