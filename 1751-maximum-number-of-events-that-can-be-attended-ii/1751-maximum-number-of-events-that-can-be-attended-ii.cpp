// prev version using an extra prev variable --easy to understand but cannot handle the dp[][][]
class Solution {
public:
    set<int>endtimes;
    int n;
    vector<vector<int>>dp;
    vector<int>startTimes;
    int f(int i, vector<vector<int>>& events, int k){
        if(i == n || k == 0){
            return 0;
        }
        if(dp[i][k] != -1)return dp[i][k];
        int take = 0;
        if(k>0){
            take = events[i][2];
            int idx = -1;
            auto itr = upper_bound(startTimes.begin(), startTimes.end(), events[i][1]);
            if(itr!=startTimes.end()){
                idx = itr - startTimes.begin();
            }
            if(idx!=-1){
                take += f(idx, events, k-1);
            }
        }
        int nottake = f(i+1,events, k);
        return dp[i][k] = max(take, nottake);
    }
                                
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        dp.resize(events.size()+1, vector<int>(k+1,-1));
        for(auto x = 0 ; x < events.size() ; x++){
            startTimes.push_back(events[x][0]);
        }
        n = events.size();
        for(auto x : events)endtimes.insert(x[1]);
        return f(0, events, k);
    }
};