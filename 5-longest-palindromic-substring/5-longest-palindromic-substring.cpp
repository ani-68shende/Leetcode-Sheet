class Solution {
public:
    string longestPalindrome(string s) {
        int maxu = 0;
        int start = 0, end = 1;
        for(int i = 1 ; i < s.size() ; i++){
            //even
            int l = i-1;
            int r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
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
                if(r-l+1 > end){
                    start = l;
                    end = r-l+1;
                }
                l--;
                r++;
            }
        }
        string gg = "";
        for(int i = start ; i <=start+end-1 ; i++){
            gg.push_back(s[i]);
        }
        return gg;
    }
};