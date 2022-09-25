class Solution {
public:
    // dillon francis 
    int maxDepth(string s) {
        int maxu = 0;
        stack<char>st;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]== '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(!st.empty()){
                    if(st.top() == '('){
                        st.pop();
                    }
                }
            }
            int n =st.size();
            maxu = max(n, maxu);
        }
        return maxu;
    }
};