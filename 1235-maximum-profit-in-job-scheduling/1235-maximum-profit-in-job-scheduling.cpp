class Solution {
public:
    int n;
    vector<int>dp;
    vector<int>startTimes;
    int f(int i, vector<vector<int>>& events){
        if(i == n){
            return 0;
        }
        if(dp[i] != -1)return dp[i];
        int take = 0;
        take = events[i][2];
        int idx = -1;
        auto itr = lower_bound(startTimes.begin(), startTimes.end(), events[i][1]);
        if(itr!=startTimes.end()){
            idx = itr - startTimes.begin();
        }
        if(idx!=-1){
            take += f(idx, events);
        }
        int nottake = f(i+1,events);
        return dp[i] = max(take, nottake);
    }
                                
    int maxValue(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        n = events.size();
        dp.resize(events.size()+1, -1);
        for(auto x = 0 ; x < events.size() ; x++){
            startTimes.push_back(events[x][0]);
        }
        return f(0, events);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>events;
        for(int i = 0 ; i < startTime.size() ; i++){
            events.push_back({startTime[i], endTime[i], profit[i]});
        }
        return maxValue(events);
    }
};