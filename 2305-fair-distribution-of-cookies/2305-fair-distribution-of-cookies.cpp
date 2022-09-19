class Solution {
public:
    int mini = INT_MAX;
    void f(int i, vector<int>& cookies, vector<int>&v){
        if(i == cookies.size()){
            int maxu = 0;
            for(int jj = 0 ; jj < v.size() ; jj++){
                if(v[jj] == 0)return ;
                maxu = max(maxu, v[jj]);
            }
            mini = min(mini, maxu);
            return;
        }
        for(int k = 0 ; k < v.size() ; k++){
            v[k] += cookies[i]   ;
            f(i+1, cookies, v);
            v[k] -= cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        // k sized vector is the ans to this question
        ios_base::sync_with_stdio(false);
cin.tie(NULL);
        vector<int> v(k, 0);
        f(0, cookies, v);
        return mini;
    }
};