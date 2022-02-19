class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int z = trust.size();
        vector<int>degree(n+1,0);
        unordered_map<int, int>zasu;
        for(auto x: trust){
            zasu[x[0]]++;
            degree[x[1]]++;
        }
        int x = *max_element(degree.begin(), degree.end());
        for(auto x = 1; x < degree.size() ; x++){
            if(degree[x] == n-1 && zasu.find(x)==zasu.end())return x;
        }
        return -1;
    }
};