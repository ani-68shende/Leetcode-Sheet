class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        if(n == 1 && s[0] == 'H')return -1;
        if(n >= 2){
            if(s[0] == 'H' && s[1] == 'H') return -1;
            if(s[n-1] == 'H' && s[n-2] == 'H') return -1;
        }
        int h = 0;
        for(auto x : s){
            if(x == 'H')h++;
        }
        int h_h = 0;
        for(int i = 0 ; i < n-2 ; i++){
            if(s[i+2] == 'H' && s[i+1] == 'H' && s[i] == 'H')return -1;
        }
        for(int i = 0 ; i < n-2 ; i++){
            
            if(s[i+2] == 'H' && s[i+1] == '.' && s[i] == 'H'){
                h_h++;
                i+=2;
            }
        }
        return h-h_h;
    }
};