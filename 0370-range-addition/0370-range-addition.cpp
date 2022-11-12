class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // line sweep
        int n = length;
        vector<int>line(n+1), pref(n);
        for(int i = 0 ; i < updates.size() ; i++){
            line[updates[i][0]]+=updates[i][2];
            line[updates[i][1]+1]-=updates[i][2];
        }
        long long sum = 0;
        //just not to get into trouble
        for(int i = 0 ; i < n ; i++){
            sum += line[i];
            pref[i] = sum;
        }
        return pref;
    }
};