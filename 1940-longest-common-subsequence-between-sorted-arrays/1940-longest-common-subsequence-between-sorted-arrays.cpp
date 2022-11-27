class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        map<int, int>mp;
        for(auto x : arrays){
            for(auto y : x){
                mp[y]++;
            }
        }
        vector<int> counto;
        for(auto x : mp){
            if(x.second == arrays.size()){
                counto.push_back(x.first);
            }
        }
        return counto;
    }
};