class Solution {
public:
    void dfs(int src, vector<int>&vis, vector<int> adj[]){
        vis[src] = 1;
        for(auto x : adj[src]){
            if(!vis[x]){
                dfs(x, vis, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        int no_of_islands = 0;
        vector<int>vis(n, 0);
        vector<int> adj[n];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i); 
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                no_of_islands++;
                dfs(i, vis, adj);
            }
        }
        return no_of_islands;
    }
};