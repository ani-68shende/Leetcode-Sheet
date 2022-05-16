class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        unordered_map<int , int >mp;
        for(auto x : edges){
            mp[x[1]]++;
        }
        for(int i = 0 ; i < n ; i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};