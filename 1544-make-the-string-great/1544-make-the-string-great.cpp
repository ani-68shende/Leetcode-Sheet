class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int n = s.size();
        for(int i = 0 ; i < s.size() ; i++){
            if(st.empty()){
               st.push(s[i]);
            }else{
                if(i <n and st.size() && (s[i] >='A' && s[i] <= 'Z' and st.top() == tolower(s[i]) || s[i] >='a' && s[i] <= 'z' and st.top() == toupper(s[i]))){
                    st.pop();
                    // i++;
                }else{
                    st.push(s[i]);
                }
            }
        }
        string temp;
        while(st.size())temp += st.top(), st.pop();
        reverse(temp.begin(),temp.end());
        return temp;
    }
};