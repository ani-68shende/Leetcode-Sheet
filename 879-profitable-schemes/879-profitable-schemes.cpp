class Solution {
public://int take nottake schema
    int N;
    int dp[101][101][101];
    int pajwa_ki_salary = (int)1000000007;
    int f(int i, int n, int total, vector<int>& group, vector<int>& profit){
        if(i >= N){
            if(total <= 0)return 1;
            else return 0;   
        }
        //god move
        if(total < 0)total = 0;
        if(dp[i][n][total]!=-1)return dp[i][n][total];
        int notpick = f(i+1, n, total, group, profit);
        int pick = 0;
        if(n-group[i] >= 0){
            pick = f(i+1, n-group[i], total-profit[i], group, profit);
        }
        return dp[i][n][total] = (notpick+pick) % pajwa_ki_salary;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N=group.size();
        int i = 0;
        int total = minProfit;
        memset(dp, -1, sizeof(dp));
        return f(i, n, total, group, profit);
    }
};