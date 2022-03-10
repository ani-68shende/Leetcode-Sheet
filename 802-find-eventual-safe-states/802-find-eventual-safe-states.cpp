class Solution {
public:
    bool dfs(int s, vector<bool>&visited, vector<vector<int>>&graph, vector<bool>&dfsvisited, vector<bool>&y){
        visited[s] = true;
        dfsvisited[s] = true;
        for(auto x: graph[s]){
            if(!visited[x]){
                if(dfs(x, visited, graph, dfsvisited,y)){
                    return y[s] = true;
                }
            }
            else if(visited[x] && dfsvisited[x]){
                return y[s] = true;
            }
        }
        dfsvisited[s] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>visited(n, false), dfsvisited(n,false);
        vector<bool>y(n,false);
        for(int i = 0 ; i < n ; i++){
            if(visited[i] == false){
                dfs(i, visited, graph, dfsvisited, y);
            }
        }
        vector<int>ans;
        for(int i =0 ; i < n ; i++){
            if(!y[i])ans.push_back(i);
        }
        return ans;
    }
};