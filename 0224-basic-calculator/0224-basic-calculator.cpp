class Solution {
public:
    int calculate(string s) {
        int sum =0;
        int sign = 1;
        stack<int> st;
        stack<int> esign;
        int num=0;
        s+=' ';
        for(char c: s){
            if(c>='0' && c<='9')
                num = num*10 + (c-'0');
            if(c=='-'){
                sum += num*sign;
                sign = -1;
                num =0;
            }
            if(c=='+'){
                sum += num*sign;
                sign = 1;
                num =0;
            }
            if(c=='('){
                st.push(sum);
                esign.push(sign);
                sign=1;
                sum=0;
                num=0;
            }
            if(c==')'){
                sum += sign*num;
                sum = st.top() + esign.top()*sum;
                st.pop();
                esign.pop();
                num=0;
            }
            if(c==' '){
                if(num==0)
                    continue;
                sum += sign *num;
                sign=1;
                num=0;
            }
        }
        return sum;
    }
};