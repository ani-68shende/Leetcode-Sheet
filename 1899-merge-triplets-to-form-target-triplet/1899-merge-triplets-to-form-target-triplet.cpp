class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> trip;
        for(auto x : triplets){
            if(x[0] <= target[0] && x[1] <= target[1] && x[2] <= target[2])
            trip.push_back(x);
        }
        vector<int>y(3,0);
        for(auto x : trip){
            y[0] = max(y[0],x[0]);
            y[1] = max(y[1],x[1]);
            y[2] = max(y[2],x[2]);
        }
        return y == target;
    }
};