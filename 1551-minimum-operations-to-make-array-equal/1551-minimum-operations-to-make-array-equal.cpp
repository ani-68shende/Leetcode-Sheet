class Solution {
public:
    int minOperations(int n) {
        //1 3 5 7               ->1+3 = 4
        //1 3 5                 ->2
        //1 3 5 7 9             ->2+4 = 6
        //1 3 5 7 9 11          ->
        // O(1) -> ofcourse space :D
        long long int sum = 0;
        for(int i = 0 ; i < n/2 ; i++){
            sum += (-(2*i-1) + (2*(n-i-1)-1))/2;
        }
        return sum;
    }
};