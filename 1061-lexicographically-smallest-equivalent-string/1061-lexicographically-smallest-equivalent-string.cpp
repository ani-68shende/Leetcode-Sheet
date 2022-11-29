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
        if(ulp_u > ulp_v) {  //major change
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n1= s1.size(), n2 = s2.size();
        if(n1!=n2)return "";
        DisjointSet ds(26);
        for(int i = 0 ; i < n1 ; i++){
            char c1 = s1[i];
            char c2 = s2[i];
            if(c1-'a' < c2-'a'){
                ds.unionBySize(c1-'a',c2-'a');
            }else{
                ds.unionBySize(c2-'a',c1-'a');
            }
        }
        string ans = "";
        for(int i = 0 ; i < baseStr.size() ; i++){
            ans += ds.findPar(baseStr[i]-'a')+'a';
        }
        return ans;
    }
};