class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int r = 0;
        for(auto x : s){
            if(x == 'R'){
                r++;
            }else{
                r--;
            }
            if(r == 0)count++;
        }
        return count;
    }
};