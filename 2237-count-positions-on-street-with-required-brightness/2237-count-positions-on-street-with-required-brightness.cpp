class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        // line sweep
        vector<long long>line(n+1), pref(n+1);
        for(int i = 0 ; i < lights.size() ; i++){
            int start = max(0, lights[i][0]-lights[i][1]);
            int end = min(n-1, lights[i][1]+lights[i][0]);
            line[start]++;
            line[end+1]--;
        }
        long long sum = 0;
        for(int i = 0 ; i < n+1 ; i++){
            sum += line[i];
            pref[i] = sum;
        }
        int counto=0;
        for(int i = 0 ; i < n ; i++){
            if(requirement[i]<=pref[i])counto++;
        }
        return counto;
    }
};