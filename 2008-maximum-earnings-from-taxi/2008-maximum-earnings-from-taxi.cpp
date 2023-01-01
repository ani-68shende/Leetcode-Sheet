class Solution {
public:
    int nn;
    vector<long long>dp;
    vector<int>startTimes;
    long long f(int i, vector<vector<int>>& events){
        if(i == nn){
            return 0;
        }
        if(dp[i] != -1)return dp[i];
        long long take = 0;
        take = events[i][1]-events[i][0]+events[i][2];
        int idx = -1;
        auto itr = lower_bound(startTimes.begin(), startTimes.end(), events[i][1]);
        if(itr!=startTimes.end()){
            idx = itr - startTimes.begin();
        }
        if(idx!=-1){
            take += f(idx, events);
        }
        long long nottake = f(i+1,events);
        return dp[i] = max(take, nottake);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        nn = events.size();
        dp.resize(events.size()+1, -1);
        for(auto x = 0 ; x < events.size() ; x++){
            startTimes.push_back(events[x][0]);
        }
        return f(0, events);
    }
};