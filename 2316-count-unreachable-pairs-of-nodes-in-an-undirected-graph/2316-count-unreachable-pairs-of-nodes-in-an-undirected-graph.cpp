class Solution {
public:
    int counto = 0;
    void dfs(int src, vector<int>adj[], vector<int>& visited){
        visited[src] = 1;
        counto++;
        for(auto x : adj[src]){
            if(!visited[x]){
                dfs(x, adj, visited);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        vector<int>visited(n, 0);
        vector<int>adj[n];
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>all;
        for(int i = 0 ;i < n ; i++){
            int ans = 0;
            counto = 0;
            if(!visited[i]){
                dfs(i, adj, visited);
                all.push_back(counto);
            }
        }
        // for(auto ss : all){
        //     cout << ss << " ";
        // }
        if(all.size() == 1)return 0;
        //alag dimag
        int n1 = all.size();
        vector<long long>v(n1);
        v[n1-1] = all[n1-1];
        for(auto i = n1-2 ; i>= 0; i--){
            v[i] = v[i+1] + all[i];
        }
        for(int i = 1 ; i < n1 ; i++){
            ans += 1LL*all[i-1]*v[i];
        }
        // cout << "\n";
        return ans;
    }
};