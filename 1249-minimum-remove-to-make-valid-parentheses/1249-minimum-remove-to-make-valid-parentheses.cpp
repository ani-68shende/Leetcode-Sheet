class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int brac = 0;
        int n = s.size();
        int countya = 0;
        for(int i = 0 ;i < n ; i++){
            if(s[i] == '(')countya++;
            else if(s[i] == ')'){
                if(countya == 0){
                    s[i] = '-';
                }else{
                    countya--;
                }
            }
        }
        countya = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == ')')countya++;
            else if(s[i] == '('){
                if(countya == 0){
                    s[i] = '-';
                }else{
                    countya--;
                }
            }
        }
        for(auto x : s)if(x!='-')ans+=x;
        return ans;
    }
};