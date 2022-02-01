class Solution {
public:
    int findLength(vector<int>& X, vector<int>& Y) {
        int m = X.size();
    int n = Y.size();
    int dp[m+1][n+1];
    int i, j;

    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
        if (i == 0 || j == 0)
            dp[i][j] = 0;
        }
    }
    int maxu = 0;
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
        if (X[i-1] == Y[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = 0;
        }
    }
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
        maxu = max(dp[i][j],maxu);
        }
    }
/* dp[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return maxu;
    }
};