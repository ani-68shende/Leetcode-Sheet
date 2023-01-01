class Solution {
public:
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
                                
    int maxTwoEvents(vector<vector<int>>& events, int k = 2) {
        sort(events.begin(), events.end());
        n = events.size();
        dp.resize(events.size()+1, vector<int>(k+1,-1));
        for(auto x = 0 ; x < events.size() ; x++){
            startTimes.push_back(events[x][0]);
        }
        return f(0, events, k);
    }
};