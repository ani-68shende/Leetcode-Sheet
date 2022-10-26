class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int c = (a*b)/__gcd(a,b);
        long long int l = 0, r = 1e15;
        int mod = (int)1e9+7;
        long long int ans = 0;
        while(l<=r){
            long long int mid = l+(r-l)/2;
            if((mid/a+mid/b-mid/c)<n){
                l=mid+1;
                ans = l;
            }else{
                r=mid-1;
            }
        }
        return ans%mod;
    }
};