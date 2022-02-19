class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>mp;
        for(auto c : edges){
            mp[c[0]].push_back(c[1]);
            mp[c[1]].push_back(c[0]);
        }
        int f = edges.size();
        vector<bool>visited(f+1, false);
        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(q.size()){
            int temp = q.front();
            q.pop();
            for(auto x : mp[temp]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        return visited[destination];
    }
};