class Solution {
public:
    int minInsertions(string s) {
        string X = s;
        reverse(s.begin(), s.end());
        string Y = s;
        int m = X.size();
        int n = Y.size();
        int L[m+1][n+1];

        for (int i=0; i<=m; i++)
        {
            for (int j=0; j<=n; j++)
            {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;

            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
        return m-L[m][n];
    }
};