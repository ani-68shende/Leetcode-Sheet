class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<long, long>mp;
        long sum = 0;
        for(int i = 0 ; i < trips.size() ; i++){
            int passengers = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];
            mp[start] += passengers;
            mp[end] -= passengers; 
        }
        for(auto x : mp){
            sum += x.second;
            if(sum > capacity){
                return false;
            }
        }
        return true;
    }
};