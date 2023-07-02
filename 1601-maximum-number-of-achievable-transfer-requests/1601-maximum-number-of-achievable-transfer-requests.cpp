class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& v) {
        int siz = v.size();
        int maxu = 0;
        for(int i = 0 ; i <= (1 << siz)-1 ; i++){
            int mask = i;
            vector<int>vis(siz, 0);
            vector<int>degree(n, 0);
            for(int j = 0 ; j <= siz ; j++){
                if( (mask & (1 << j)) ){
                    degree[v[j][0]]++;
                    degree[v[j][1]]--;
                }
            }
            bool flag = true;
            for(int k = 0 ; k < n ; k++){
                if(degree[k]!=0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                maxu = max(maxu, __builtin_popcount(i));
            }
        }
        return maxu;
    }
};