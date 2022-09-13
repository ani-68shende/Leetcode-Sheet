#define ll long long int
class Solution {
public:
    bool ff(int i, vector<ll> p, int n){
        if(n == 0)return true;
        if(i < 0){
            return false;
        }
        bool notpick = ff(i-1, p, n);
        bool pick = false;
        if(n-p[i] >=0){
            pick = ff(i-1, p, n-p[i]);
        }
        return pick | notpick;
    }
    bool checkPowersOfThree(int n) {
        vector<ll>p;
        ll f = 1;
        for(int j(1) ; j <= 16 ; j++){
            p.push_back(f);
            f = f * 3;
        }
        int i = p.size()-1;
        return ff(i, p, n);
    }
};