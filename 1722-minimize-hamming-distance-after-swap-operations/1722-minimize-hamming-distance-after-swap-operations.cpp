class Solution {
public:
    
    vector<int> rank_depth, parent;
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        makeSet();
        int n = target.size();
        map<int, multiset<int>>mp;
        for(auto x : allowedSwaps)(union_nodes(x[0], x[1]));
        for(int i = 0 ; i < n ; i++){
            int parentid = findPar(i);
            mp[parentid].insert(source[i]);
        }
        int count = 0;
        for(int i = 0 ; i < n ;i++){
            int parentid = findPar(i);
            if(mp[parentid].count(target[i]))
                mp[parentid].erase(mp[parentid].lower_bound(target[i]));
            else 
                count++;
        }
        return count;
    }
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
    //just change to bool
    bool union_nodes(int u, int v)
    {
        // go directly for parents we are not concerned about the nodes
        u = findPar(u);
        v = findPar(v);
        if(u == v)return true;
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
        return false;
    }
};