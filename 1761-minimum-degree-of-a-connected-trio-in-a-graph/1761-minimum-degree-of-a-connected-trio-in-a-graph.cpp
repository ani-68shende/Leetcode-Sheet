class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int res = INT_MAX;
        vector<vector<int>>adj(n+1, vector<int>(n+1,0));
        vector<int>degree(n+1,0);
        for(auto x : edges){
            adj[x[0]][x[1]] = 1;
            adj[x[1]][x[0]] = 1;
            degree[x[0]]++, degree[x[1]]++;
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = i+1 ; j <= n ; j++){
                for(int k = j+1; k  <= n ;k++){
                    if(adj[i][j] && adj[j][k] && adj[k][i]){
                        res = min(res,degree[i] + degree[j] + degree[k]-6);
                    }
                }
            }
        }
        if(res == INT_MAX)return -1;
        return res;
    }
};