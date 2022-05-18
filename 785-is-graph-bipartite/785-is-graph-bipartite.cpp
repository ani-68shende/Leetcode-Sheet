class Solution {
public:
    bool bipartiteBFS(int src, vector<vector<int>> adj, vector<int> color)
    {
        queue<int>q;
        q.push(src); 
        color[src] = 1; 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop();
            for(auto it : adj[node]) {
                if(color[it] == -1) {
                    color[it] = 1 - color[node]; 
                    q.push(it); 
                } else if(color[it] == color[node]) {
                    return false; 
                }
            }
        }
        return true; 
    }
    bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();    
    vector<int> color(n, -1);
    // here n is the number of nodes
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBFS(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
    }
};