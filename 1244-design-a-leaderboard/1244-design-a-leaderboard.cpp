class Leaderboard {
public:
    unordered_map<int, int>mp;
    Leaderboard() {
        
    }
    
    void addScore(int PlayerId, int score) {
        mp[PlayerId] += score;
    }
    
    int top(int K) {
        vector<pair<int, int>>v;
        for(auto x : mp){
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end(),greater<pair<int, int>>());
        int sum = 0;
        for(int i = 0 ; i < K ; i++)sum += v[i].first;
        return sum;
    }
    
    void reset(int PlayerId) {
        mp.erase(PlayerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */