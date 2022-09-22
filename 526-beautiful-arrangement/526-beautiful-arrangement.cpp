class Solution {
public:
    int count = 0;
    void f(int i, int n, vector<int> v){
        if(i > n){
            count++;
            return ;
        }
        for(int k = 1 ; k <= n ;k++){
            if(v[k] == 0){
                if(k%i==0 || i%k==0){
                v[k] = 1;
                f(i+1, n, v);
                v[k] = 0;
            }
        }
    }
    }
    int countArrangement(int n) {
        vector<int>v(n+1,0);
        f(1, n, v);
        return count;
    }
};