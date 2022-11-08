class Solution {
public:
    bool batao_bhai = false;
    void cycle(int src, vector<int> adj[], vector<int>& visited, int parent){
        visited[src] = 1;
        for(auto x : adj[src]){
            if(!visited[x]){
                cycle(x,adj,visited,src);
            }else if(x != parent){
                batao_bhai = true;
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>visited(n);
        vector<int> adj[n];
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int count = 0;
        for(int i= 0 ; i < n ; i++){
            if(!visited[i]){
                if(count >=1)return false;
                cycle(i,adj,visited,-1);
                if(batao_bhai)return false;
                count++;
            }
        }
        return true;
    }
};