class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin() , s.end());
        sort(t.begin() , t.end());
        int i = 0; 
        int j  =0;
        char s1 = t[j];
        while(s[i]==t[j] && i <s.size() && j < t.size()){
            i++;j++;
            s1 = t[j];
        }
        return s1; 
    }
};