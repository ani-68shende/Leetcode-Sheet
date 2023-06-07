class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count(0);
        for(int i = 0 ; i < 32 ; i++){
            if(c&(1<<i)){
                if(!(a&(1<<i)) && !(b&(1<<i))){
                    count++;
                }
            }else{
                if(a&(1<<i))count++;
                if(b&(1<<i))count++;
            }
        }
        return count;
    }
};