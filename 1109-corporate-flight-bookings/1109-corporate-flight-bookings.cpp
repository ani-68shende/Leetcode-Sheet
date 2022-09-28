class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans;
        vector<int>pref(1e5, 0);
        for(auto x : bookings){
            pref[x[0]]+=x[2];
            pref[x[1]+1]+=-x[2];
        }
        int sum(0);
        for(auto i = 1 ; i <= n ;i++){
            sum += pref[i];
            ans.push_back(sum);
        }
        return ans;
    }
};