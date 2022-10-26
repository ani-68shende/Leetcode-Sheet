class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0;
        int r = sqrt(c);
        while(l <= r){
            if(1LL*l*l+r*r == 1LL*c)return true;
            else if(1LL*l*l+r*r<1LL*c){
                l+=1;
            }else{
                r-=1;
            }
        }return false;
    }
};