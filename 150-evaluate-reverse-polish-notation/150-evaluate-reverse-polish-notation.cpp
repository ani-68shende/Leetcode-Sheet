class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int>st; 
        for(int i = 0 ; i < tokens.size() ; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                long long int n1 = st.top();
                st.pop();
                long long int n2 = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    st.push(n1+n2);
                }if(tokens[i] == "-"){
                    st.push(n2-n1);
                }if(tokens[i] == "*"){
                    st.push(n1*n2);
                }if(tokens[i] == "/"){
                    st.push(n2/n1);
                }
            }else {
                long long int num = 1;
                if(tokens[i][0] == '-'){
                    num*=-1;
                    tokens[i].erase(0,1);
                }
                cout << tokens[i] << endl;
                num*=stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};