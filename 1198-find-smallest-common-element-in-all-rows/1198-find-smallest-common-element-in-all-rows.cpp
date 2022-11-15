class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int, int>mp;
        for(auto x : mat){
            set<int>s;
            for(auto y : x){
                s.insert(y);
            }
            for(auto x1 : s)mp[x1]++;
        }
        int mini = INT_MAX;
        for(auto x : mp){
            if(x.second == mat.size())mini = min(x.first,mini);
        }
        return mini == INT_MAX ? -1 : mini;
    }
};