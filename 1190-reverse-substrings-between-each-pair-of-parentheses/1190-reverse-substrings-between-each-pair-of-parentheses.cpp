class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<int>st;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                int tops = st.top();
                st.pop();
                //god move
                reverse(s.begin()+tops+1, s.begin()+i);
            }
        }
        for(auto x : s)if(x!='('&&x!=')')ans+=x;
        return ans;
    }
};