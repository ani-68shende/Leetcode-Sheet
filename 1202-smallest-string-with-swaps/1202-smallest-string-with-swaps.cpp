class DSU
{
private:
    vector<int> rank_depth, parent;

public:
    void makeSet()
    {
        parent.resize(100005);
        rank_depth.resize(100005);
        for (int i = 0; i < 100000; i++)
        {
            parent[i] = i; // each of the nodes are the parent of itself initially
            rank_depth[i] = 0;
        }
    }

    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]); // path compression
    }

    void union_nodes(int u, int v)
    {
        // go directly for parents we are not concerned about the nodes
        u = findPar(u);
        v = findPar(v);
        if (rank_depth[u] < rank_depth[v])
        {
            parent[u] = v;
        }
        else if (rank_depth[u] > rank_depth[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank_depth[u]++;
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DSU obj;
        obj.makeSet();
        int n = s.size();
        map<int, priority_queue<char, vector<char>, greater<char>>>mp;
        for(auto x : pairs)(obj.union_nodes(x[0], x[1]));
        for(int i = 0 ; i < n ; i++){
            int parid = obj.findPar(i);
            mp[parid].push(s[i]);
        }
        for(int i = 0 ; i < n ; i++){
            int parentid = obj.findPar(i);
            s[i] = mp[parentid].top();
            mp[parentid].pop();
        }
        return s;
    }
};