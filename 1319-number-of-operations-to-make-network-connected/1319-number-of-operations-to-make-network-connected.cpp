class Solution {
public:
    void dfs(unordered_map<int, vector<int>>&mp ,int i, vector<bool>&visited){
        visited[i] = true;
        for(auto x : mp[i]){
            if(!visited[x]){
                dfs(mp, x, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int components = 0;
        int edges = 0;
        unordered_map<int, vector<int>>mp;
        for(auto x : connections){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
            edges++;
        }
        vector<bool>visited(n, 0);
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                components++;
                dfs(mp,i,visited);
            }
        }
        // The most important ofrmula or algorithm you can say.....
        if(edges < n-1){
            return -1;
        }
        int reduntant_edges = edges - n + components;
        if(reduntant_edges >= components-1){
            return components-1;
        }
        return -1;
    }
};