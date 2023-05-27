// will need to do it again
class Solution {
public:int dp[50001][2];
    int f(int i, vector<int>& v, int turn){
        if(i >= v.size()){
            return 0;
        }
        if (dp[i][turn] != -1) return dp[i][turn];
        int ans, s = 0;
        int gg = v.size();
        int cc = min(3+i,gg);
        if(!turn){
            ans = INT_MIN;
            for(int ni = i ; ni < cc ; ni++){
                s += v[ni];
                ans = max(ans, s+f(ni+1,v, 1));
            }
        }else{
            ans = INT_MAX;
            for(int ni = i ; ni < cc ; ni++){
                // s += v[ni];
                ans = min(ans, f(ni+1,v, 0));
            }
        }
        return dp[i][turn] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int s = 0;memset(dp, -1, sizeof dp);
        int totalScore = 0;
        for (auto i : stoneValue) totalScore += i;
        int aliceScore = f(0, stoneValue, 0);
        if (totalScore - aliceScore > aliceScore)
            return "Bob";
        else if (totalScore - aliceScore < aliceScore)
            return "Alice";
        return "Tie";
    }
};