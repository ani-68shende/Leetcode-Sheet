
class Solution {
public:
    bool check(int n){
        vector<int>mp(10, 0);
        int d = n;
        while(n){
            mp[n%10]++;
            n/=10;
        }
        for(int i = 0 ; i < 10 ; i++){
            if(mp[i] > 0 && mp[i] != i)return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        n++;
        for(int i = n ; i <= 1e7 ; i++){
            if(check(i))return i;
        }
        return n;
    }
};