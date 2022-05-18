class Solution {
public:
    // here degree 1 nodes are streated as in degree 0 nodes
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0){
            return {};
        }
        if(n == 1){
            return {0};
        }
        vector<int> degree(n, 0);
        vector<int> adj[n];
        for(auto x: edges){
            adj[x[1]].push_back(x[0]);
            adj[x[0]].push_back(x[1]);
            degree[x[0]]++;
            degree[x[1]]++;
        }
        queue<int>q;
        int src = 0;
        for(auto x  = 0 ; x < degree.size() ; x++){
            if(degree[x] == 1){
                q.push(x);
            }
        }
        vector<int>ana;
        while(q.size()){
            ana.clear();
            int siz = q.size();
            for(int i = 0 ; i < siz ; i++){
                int node = q.front(); // traversing level by level
                q.pop();
                ana.push_back(node);
                for(auto neighbor : adj[node]){
                    degree[neighbor]--;
                    if(degree[neighbor] == 1){
                        q.push(neighbor);
                    }
                }
            }
        }
        return ana;
    }
};