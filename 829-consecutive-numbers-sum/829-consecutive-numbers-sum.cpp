class Solution {
public:
    //see pepecoding video on youtube
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for(int k = 1 ; k*(k-1) < 2*n ; k++){
            if((n-k*(k-1)/2) % k == 0)count++;
        }
        return count;
    }
};