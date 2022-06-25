class Solution {
public:
    long long f(int ind, vector<long long>& points, vector<long long>& brainpower, vector<long long>& dp){
        if(ind == points.size()-1){
            return points[ind];
        }
        if(ind > points.size()-1){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        long long notTake = 0 + f(ind+1, points, brainpower, dp);
        long long take = points[ind] +  f(ind+brainpower[ind]+1, points, brainpower, dp);
        return dp[ind]=max(notTake, take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>points;
        vector<long long>brainpower;
        int n = questions.size();
        vector<long long>dp(n,-1);
        for(int i = 0 ; i < n ; i++){
            points.push_back(questions[i][0]);
            brainpower.push_back(questions[i][1]);
        }
        return f(0, points, brainpower, dp);
    }
};