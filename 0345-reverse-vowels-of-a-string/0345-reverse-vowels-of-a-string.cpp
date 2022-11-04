class Solution {
public:
    string reverseVowels(string s) {
        set<char>st{'a','e','i','o','u','A','E','I','O','U'};
        int i = 0, j = s.size()-1;
        while(i <= j){
            if(st.count(s[i]) && st.count(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }else if(st.count(s[i]) && !st.count(s[j])){
                j--;
            }else if(!st.count(s[i]) && st.count(s[j])){
                i++;
            }else{
                i++,j--;
            }
        }
        return s;
    }
};