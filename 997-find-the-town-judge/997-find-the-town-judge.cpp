class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int z = trust.size();
        vector<int>degree(n+1,0);
        for(auto x: trust){
            degree[x[0]]--;
            degree[x[1]]++;
        }
        int x = *max_element(degree.begin(), degree.end());
        for(auto x = 1; x < degree.size() ; x++){
            if(degree[x] == n-1)return x;
        }
        return -1;
    }
};