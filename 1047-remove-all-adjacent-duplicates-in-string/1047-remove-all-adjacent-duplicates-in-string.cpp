class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char>st;
        for(int i = 0 ; i < s.size() ; i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(st.size() && st.top() == s[i]){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        string temp = "";
        while(st.size()){
            temp = st.top() + temp;
            st.pop();
        }
        return temp;
    }
};