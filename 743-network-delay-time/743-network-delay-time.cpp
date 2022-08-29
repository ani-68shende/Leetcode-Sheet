class Solution {
public:
    // 1 based indexing be careful
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<pair<int, int>> adj[n];
        vector<int>cost(n, 0);
        vector<int>visited(n, false);
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]-1].push_back({edges[i][2], edges[i][1]-1});
            //                                 dist, node    
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
        //        dist, node  
        int src = k-1;
        q.push({0, src});
        while(!q.empty()){
            auto node = q.top();
            q.pop();
            int currnode = node.second;
            int currcost = node.first;
            if(visited[currnode])
                continue;
            visited[currnode] = true;
            cost[currnode] = currcost;
            for(auto child : adj[currnode]){
                int childnode = child.second;
                int childcost = child.first;
                if(visited[childnode])
                    continue;
                q.push({currcost + childcost, childnode});
            }
        }
        for(auto x : visited){
            if(!x)return -1;
        }
        
        int max_time = 0 ;
        for(auto x : cost){
            max_time = max(max_time, x);
        }
        return max_time;
    }
};