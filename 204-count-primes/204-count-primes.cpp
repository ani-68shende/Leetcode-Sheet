class Solution {
public:
    // ruk tereko false karta mai...iss basis pe chalta ye algo
    int countPrimes(int n) {
       vector<bool>primes(1+n,true) ;
        for(int p = 2 ;  p*p <= n ; p++){
            if(primes[p]){
                for(int i = p*p ; i <= n ; i+=p){
                    primes[i] = false;
                }
            }
        }
        int countya = 0;
        for(auto x(2);x < primes.size()-1 ; x++)if(primes[x])countya++;
        return countya; 
    }
};