class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& iT) {
        vector<pair<int, int>> adj[n];
        int src;
        for(int i = 0 ; i < manager.size() ; i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back({i, iT[i]});
            else
                src = i;
        }
        queue<pair<int, int>>q;
                 //nod, csot
        int maxu = 0;
        q.push({src, iT[src]});
        while(!q.empty()){
            auto x = q.front();
            int node = x.first;
            int cost = x.second;
            q.pop();
            for(auto y : adj[node]){
                int newNode = y.first;
                int newCost = y.second;
                q.push({newNode, newCost+cost});
                maxu = max(newCost+cost, maxu);
            }
        }
        return maxu;
    }
};