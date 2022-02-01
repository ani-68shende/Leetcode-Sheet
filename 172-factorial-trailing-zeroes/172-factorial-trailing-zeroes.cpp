class Solution {
public:
    int trailingZeroes(int N) {
       // Here I am taking the concept of jee of greatest intger function which shall divide the number by 5's powers until the number becomes zero;
        int ans = 0;
        for(int i = 5 ; (N/i) ; i=i*5)ans+=N/i;
        return ans;
    }
};