#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
public: 
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n, 0); 
        parent.resize(n);
        size.resize(n); 
        for(int i = 0;i<n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findPar(u); 
        int ulp_v = findPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findPar(u); 
        int ulp_v = findPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
public:
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        set<pair<int, int>>visited;
        DisjointSet ds(m*n);
        vector<int>islands;
        int count = 0;
        for(auto pos : positions){
            int x = pos[0];
            int y = pos[1];
            if(visited.count({x,y})){
                islands.push_back(count);
                continue;
            }
            visited.insert({x,y});
            count++;
            int node = x*n+y;
            if(x-1>=0){
                int currnode = (x-1)*n+y;
                if(visited.count({x-1,y})){
                    if(ds.findPar(node) != ds.findPar(currnode)){
                        count--;
                        ds.unionBySize(node, currnode);
                    }
                }
            }
            if(x+1<m){
                int currnode = (x+1)*n+y;
                if(visited.count({x+1,y})){
                    if(ds.findPar(node) != ds.findPar(currnode)){
                        count--;
                        ds.unionBySize(node, currnode);
                    }
                }
            }
            if(y-1>=0){
                int currnode = x*n+y-1;
                if(visited.count({x,y-1})){
                    if(ds.findPar(node) != ds.findPar(currnode)){
                        count--;
                        ds.unionBySize(node, currnode);
                    }
                }
            }
            if(y+1<n){
                int currnode = x*n+y+1;
                if(visited.count({x,y+1})){
                    if(ds.findPar(node) != ds.findPar(currnode)){
                        count--;
                        ds.unionBySize(node, currnode);
                    }
                }
            }
            islands.push_back(count);
        }
        return islands;
    }
};