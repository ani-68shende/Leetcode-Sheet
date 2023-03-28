class Solution {
public:
    int one, two, three, n;
    int dp[366];
    int ff(int i, vector<int>& days){
        if(i >= days.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int take1 = INT_MAX, take2 = INT_MAX, take3 = INT_MAX;
        int ini = days[i];
        auto i1 = lower_bound(days.begin(), days.end(), days[i]+30) - days.begin();
        take1 = three + ff(i1, days);
        auto i2 = lower_bound(days.begin(), days.end(), days[i]+7) - days.begin();
        take2 = two + ff(i2, days);
        take3 = one + ff(i+1, days);
        return dp[i]=min({take1, take2, take3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        memset(dp, -1, sizeof(dp));
        one = costs[0], two = costs[1], three = costs[2];
        return ff(0, days);
    }
};