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
    
    int largestIsland(vector<vector<int>>& grid) {
        int m, n; //
        n = m = grid.size(); //
        vector<vector<int>>positions;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    positions.push_back({i,j});
                }
            }
        }
        set<pair<int, int>>visited;
        DisjointSet ds(m*n);
        vector<int>islands;
        int count = 0;
        for(auto pos : positions){
            int x = pos[0];
            int y = pos[1];
            if(visited.count({x,y})){
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
        }
        // return islands;
        int max_no_of_islands = 0;
        for(auto x : ds.size){
            max_no_of_islands = max(max_no_of_islands, x);
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){ //as it is a square matrix
                if(visited.count({i,j}))continue;
                int x = i;
                int y = j;
                // cout <<x <<  " " << y << endl;
                int no_of_islands = 0;
                unordered_map<int, int>mp; // parent
                if(x-1>=0){
                    int currnode = (x-1)*n+y;
                    if(visited.count({x-1,y})){
                        int par = ds.findPar(currnode);
                        no_of_islands += ds.size[par];
                        mp[par]++;
                    }
                }
                if(x+1<m){
                    int currnode = (x+1)*n+y;
                    if(visited.count({x+1,y})){
                        int par = ds.findPar(currnode);
                        if(!mp.count(par))
                            no_of_islands += ds.size[par];
                        mp[par]++;
                    }
                }
                if(y-1>=0){
                    int currnode = x*n+y-1;
                    if(visited.count({x,y-1})){
                        int par = ds.findPar(currnode);
                        if(!mp.count(par))
                            no_of_islands += ds.size[par];
                        mp[par]++;
                    }
                }
                if(y+1<n){
                    int currnode = x*n+y+1;
                    if(visited.count({x,y+1})){
                        int par = ds.findPar(currnode);
                        if(!mp.count(par))
                            no_of_islands += ds.size[par];
                        mp[par]++;
                    }
                }
                max_no_of_islands = max(max_no_of_islands, no_of_islands+1);
            }
        }
        return max_no_of_islands;
    }
};