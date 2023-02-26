class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], pro[i]});
            adj[edges[i][1]].push_back({edges[i][0], pro[i]});   
        }
        vector<int> visited(n, 0);
        priority_queue<pair<double, int>>pq;
        vector<double>dist(n, 0);
        dist[start] = 1.0;
        pq.push({(double)1.0, start});
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            double prob = x.first;
            int node = x.second;
            if(visited[node])continue;
            visited[node] = 1;
            for(auto x : adj[node]){
                if(dist[x.first] < dist[node]*x.second){
                    dist[x.first] = dist[node]*x.second;
                    pq.push({dist[x.first], x.first});
                }
            }
        }
        return dist[end];
    }
};