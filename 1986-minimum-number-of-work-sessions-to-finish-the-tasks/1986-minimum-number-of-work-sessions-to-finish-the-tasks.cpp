class Solution {
public:
    int n;
    int dp[16][1<<15];
    int ff(vector<int>& tasks, int sessionTime, int time, int mask){
        if(__builtin_popcount(mask) == n){
            return 0;
        }
        if(dp[time][mask] != -1)return dp[time][mask];
        int take1 = INT_MAX, take2 = INT_MAX;
        for(int i = 0; i< n ; i++){
            if((mask & (1<<i)) == 0){
                if(time + tasks[i] <= sessionTime){
                    take1 = min(take1, ff(tasks, sessionTime, time + tasks[i], (mask | (1 << i))));
                }else{
                    take2 = min(take2, 1 + ff(tasks, sessionTime, tasks[i], (mask | (1 << i))));
                }
                // break;
            }
        }
        return dp[time][mask] = min(take1, take2);
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        n = tasks.size();
        memset(dp, -1, sizeof(dp));
        int time = 0, i = 0, mask = 0;
        return ff(tasks, sessionTime, time, mask)+1;
    }
};