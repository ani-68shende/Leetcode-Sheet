class DSU
{
private:
    // vector<int> rank_depth, parent;

public:
    vector<int> rank_depth, parent;
    void makeSet(int n = 100005)
    {
        parent.resize(n);
        rank_depth.resize(n);
        for (int i = 0; i < n; i++)
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
    bool connected(int u, int v){
        return (findPar(u) == findPar(v));
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests){
        DSU obj;
        obj.makeSet(n);
        vector<bool>values;
        int nn =  requests.size();
        for(int i = 0 ; i < nn ; i++){
            int u = requests[i][0], v = requests[i][1];
            vector<int>temp_parent=obj.parent, temp_rank =obj.rank_depth;
            obj.union_nodes(u, v);
            bool ok = true;
            for(auto x : restrictions){
                if(obj.connected(x[0],x[1])){
                    ok=false;
                    break;
                }
            }
            if(!ok){
                obj.parent = temp_parent, obj.rank_depth = temp_rank;
            }
            values.push_back(ok);
        }
        return values;
    }
};