class Solution {
public:
    int f(int i, int j, vector<int>& piles, int alice, vector<vector<vector<int>>>& dp){
        if(i > j){
            return 0;
        }
        int val1, val2;
        if(dp[i][j][alice]!=-1)return dp[i][j][alice];
        //when alice is playing
        if(alice){
            val1 = piles[i] + f(i+1, j, piles, 0, dp);
            val2 = piles[j] + f(i, j-1, piles, 0, dp);
            return dp[i][j][alice] =  max(val1, val2);
        }
        
        //when bob is playing
        val1 = -piles[i] + f(i+1, j, piles, 1, dp);
        val2 = -piles[j] + f(i, j-1, piles, 1, dp);
        return dp[i][j][alice] = min(val1, val2);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int alice = 1;
        int i = 0;
        int j = n-1;
        vector<vector<vector<int>>>dp(piles.size(), vector<vector<int>>(piles.size(), vector<int>(2,-1)));
        int f2 = f(i, j, piles, alice, dp);
        // cout << f2 << "\n";
        return f2;
    }
};