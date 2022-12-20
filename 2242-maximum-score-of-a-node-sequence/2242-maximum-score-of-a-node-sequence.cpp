class Solution {
public:
    int maximumScore(vector<int>& ss, vector<vector<int>>& edges) {
        //fix middle 2
        long long maxu = -1;
        long long n = ss.size();
        vector<vector<long long>>adj(n);
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(auto i = 0 ; i < adj.size() ; i++){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
            for(auto x : adj[i]){
                pq.push({ss[x], x});
                if(3 < pq.size()){
                    pq.pop();
                }
            }
            vector<int>temp;
            while(pq.size()){
                temp.push_back(pq.top().second);
                pq.pop();
            }
            adj[i].resize(0);
            for(auto x : temp)adj[i].push_back(x);
        }
        for(auto x : edges){
            long long u = x[0];
            long long v = x[1];
            long long n1 = adj[u].size();
            for(long long i = 0 ; i < min(3*1LL, n1) ; i++){
                long long x = adj[u][i];
                if(x == v)continue;
                long long n2 = adj[v].size();
                for(long long j = 0 ; j < min(3*1LL, n2) ; j++){
                    long long y = adj[v][j];
                    if(y == u || y == x)continue;
                    maxu = max(maxu, 1LL*ss[u]+ss[v]+ss[y]+ss[x]);
                }
            }
        }
        return maxu;
    }
};