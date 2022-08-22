class Solution {
public:
    int countSubstrings(string s) {
        int suma = s.size();
        int start = 0, end = 1;
        for(int i = 1 ; i < s.size() ; i++){
            //even
            int l = i-1;
            int r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                suma++;
                if(r-l+1 > end){
                    start = l;
                    end = r-l+1;
                }
                l--;
                r++;
            }
            //odd
            l = i-1;
             r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                suma++;
                if(r-l+1 > end){
                    start = l;
                    end = r-l+1;
                }
                l--;
                r++;
            }
        }
        return suma;
    }
};