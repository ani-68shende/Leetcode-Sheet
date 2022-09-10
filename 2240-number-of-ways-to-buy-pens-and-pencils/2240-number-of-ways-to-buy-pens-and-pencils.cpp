class Solution {
public:
//     long long nCr(long long n, long long r)
//     {
//         return fact(n) / (fact(r) * fact(n - r));
//     }

//     // Returns factorial of n
//     long long fact(long long n)
//     {
//         if(n==0)
//         return 1;
//         long long res = 1;
//         for (long long i = 2; i <= n; i++)
//             res = res * i;
//         return res;
//     }
    long long waysToBuyPensPencils(int total, int pen, int pencil) {
        long long count(0);
        int j = 0;
        while(pen*j <= total){
            count+= (1+((total-pen*j*1LL)/pencil));
            j++;
        }
        return count;
    }
};