class Solution {
public:
    int addDigits(int num) {
        if(num == 0)return 0;
        while(num > 9){
            int y = num;
            int sum = 0;
            while(y>0){
                int d = y%10;
                sum += d;
                y /= 10;
            }
            num = sum;
        }
        return num;
    }
};