class Solution {
public:
    int mini = 1e8;
    void f(int i, vector<int>& kk, vector<int> & jobs){
        // op++ move
        int maxu = *max_element(kk.begin(), kk.end());
        if(mini < maxu)return ;
        if(i>=jobs.size()){
            mini = min(mini, maxu);
            return ;
        }
        for(int k = 0 ; k < kk.size() ; k++){
            // god or what move... as two workers can have the same amount of work then we can skip one of them
            if(k>0 && kk[k-1] == kk[k])continue;
            kk[k]+=jobs[i];
            f(i+1, kk, jobs);
            kk[k]-=jobs[i];
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>kk(k, 0);
        f(0,kk, jobs);
        return mini;
    }
};