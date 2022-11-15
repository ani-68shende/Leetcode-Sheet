class Solution {
public:
    int longestPalindromeSubseq(string X) {
        int m = X.size();
    string Y;
    int n = X.size();
    for(int i = 0 ; i < m ; i++)
    {
        Y.push_back(X[m-i-1]);
    }
    int L[m+1][n+1];
    int i, j;

    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
        if (i == 0 || j == 0)
            L[i][j] = 0;
    
        else if (X[i-1] == Y[j-1])
            L[i][j] = L[i-1][j-1] + 1;
    
        else
            L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
     
/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
    }
    bool isValidPalindrome(string s, int k) {
        return s.size()-longestPalindromeSubseq(s) <= k;
    }
};