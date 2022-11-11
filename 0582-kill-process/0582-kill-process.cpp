class Solution {
public:
    vector<int>sol;
    // vector<int>visited(1e5+5);
    void dfs(int src, unordered_map<int, vector<int>>&adj){
        sol.push_back(src);
        for(auto x : adj[src]){
            dfs(x,adj);
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>>adj;
        int root = -1;
        for(int i = 0 ; i < pid.size() ; i++){
            if(ppid[i] == 0){
                root = pid[i];
            }else{
                adj[ppid[i]].push_back(pid[i]);
            }
        }
        dfs(kill, adj);
        return sol;
    }
};