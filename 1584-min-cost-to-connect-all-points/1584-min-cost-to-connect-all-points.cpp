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
    int minCostConnectPoints(vector<vector<int>>& logs) {
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        int n = logs.size();
        for(int i(0) ; i < n ; i++){
            for(int j(i+1) ; j < n ; j++){
                pq.push({abs(logs[i][0]-logs[j][0])+abs(logs[i][1]-logs[j][1]), {i, j}});
            }
        }
        DisjointSet ds(n);
        int total = 0;
        while(pq.size()){
            auto f = pq.top();
            pq.pop();
            int dist = f.first;
            int x = f.second.first;
            int y = f.second.second;
            if(ds.findPar(x) == ds.findPar(y)){
                continue;
            }
            ds.unionBySize(x,y);
            total += dist;
        }
        return total;
    }
};