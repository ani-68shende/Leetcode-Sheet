class Solution {
public:
    vector<int> S;
    unordered_map<int, int>mp;
    set<vector<int>>s;
    vector<vector<int>> permuteUnique(vector<int>& tiles) {
        vector<vector<int>>ha;
        solve(tiles);
        int n = tiles.size();
        for(auto x : s){
            if(x.size() == n)
            ha.push_back(x);
        }
        return ha;
    }
    void solve(vector<int> tiles){
        for(int i = 0 ;i < tiles.size(); i++){
            if(!mp[i]){
                mp[i] = 1;
                S.push_back(tiles[i]);
                s.insert(S);
                solve(tiles);
                mp[i] = 0;
                S.pop_back();
            }
        }
    }
};