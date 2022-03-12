class Solution {
public:
    bool dfs(int s, vector<bool>&visited, vector<vector<int>>&graph, vector<bool>&dfsvisited, vector<int>& ans){
        visited[s] = true;
        dfsvisited[s] = true;
        for(auto x: graph[s]){
            if(!visited[x]){
                if(dfs(x, visited, graph, dfsvisited, ans)){
                    return true;
                }
            }
            else if(visited[x] && dfsvisited[x]){
                return true;
            }
        }
        ans.push_back(s);
        dfsvisited[s] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        int n = numCourses;
        for(auto x : prerequisites){
            graph[x[0]].push_back(x[1]);
        }
        vector<int>ans;
        vector<bool>visited(n, false), dfsvisited(n,false);
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                if(dfs(i, visited, graph, dfsvisited, ans))return {};
            }
        }
        return ans;
    }
};