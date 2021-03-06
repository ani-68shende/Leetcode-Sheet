class Solution {
public:
    bool bipartiteBFS(int node, vector<vector<int>> adj, vector<int> color)
    {
        color[node] = 1;
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int it = q.front();
            q.pop();
            for (auto child : adj[it])
            {
                if (color[child] == -1)
                {
                    color[child] = 1 - color[it];
                    q.push(child);
                }
                else if (color[child] == color[it])
                {
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