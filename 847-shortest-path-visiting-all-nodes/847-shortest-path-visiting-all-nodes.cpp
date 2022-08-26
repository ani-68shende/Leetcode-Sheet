class Solution {
public:
    // visited <pair <int, int>>vis;
    //                node, mask //to check whether it is visited check yourself at 0:)->1:)->0;)->1:( ... this is because we have {1, 011} already visited
    // queue<pair<int, pair<int, int>>
    //.           node      dis, mask
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int all = (1<<n)-1;
        set<pair<int, int>>vis;
        queue<pair<int, pair<int, int>>>q;
        int mask = 0;
        for(int i = 0 ; i < n ;i++){
            mask = (1<<i);
            vis.insert({i, mask});
            q.push({i, {0, mask}});
        }
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int node = x.first, dist = x.second.first, mask = x.second.second;
            for(auto ng : graph[node]){
                int newMask = (1<<ng) | mask;
                if(newMask == all)return dist+1;
                if(vis.count({ng, newMask})) continue ;
                else{
                    q.push({ng, {dist+1, newMask}});
                    vis.insert({ng, newMask});
                }
            }
        }
        return 0;
    }
};