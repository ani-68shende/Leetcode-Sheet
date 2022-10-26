class Solution {
public:
    bool isPerfectSquare(int c) {
        long long int l = 1;
        long long int r = 1e6;
        while(l <= r){
            long long int mid = l+(r-l)>>2;
            if((long long int)mid*mid == (long long int)c)return true;
            else if((long long int)mid*mid < (long long int)c){
                l+=1;
            }else{
                r-=1;
            }
        }return false;
    }
};