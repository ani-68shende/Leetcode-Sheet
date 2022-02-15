class Solution {
public:
    string S;
    unordered_map<int, int>mp;
    set<string>s;
    int numTilePossibilities(string tiles) {
        solve(tiles);
        return s.size();
    }
    void solve(string tiles){
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