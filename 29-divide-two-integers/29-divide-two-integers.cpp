#define ll long long
class Solution {
public:
    int divide(int n, int m) {
        if(n == INT_MIN && m == -1)return INT_MAX;
        if(n == INT_MIN && m == 1)return n;
        ll sign = (n < 0) ^ (m < 0);
        ll dividend=abs(n);
        ll divisor=abs(m);
        ll num = 0;
        ll ans = 0;
        for(int i = 31; i >= 0 ; i--){
            if(num + (divisor<<i) <= dividend){
                ans |= (1<<i);
                num += (divisor<<i);
            }  
        }
        return sign ? -ans : ans;
    }
};