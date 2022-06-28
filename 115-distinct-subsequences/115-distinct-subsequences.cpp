class Solution {
public:
    int numDistinct(string text1, string text2) {
        int n = text1.size(), m= text2.size(); 
        vector<vector<double>> lookup(n+1, vector<double>(m+1, 0));
        for (int k = 0; k <= n; k++) lookup[k][0] = 1;
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(text1[i-1] == text2[j-1])
                    lookup[i][j] = lookup[i-1][j-1] + lookup[i-1][j];
                else
                    lookup[i][j] = lookup[i-1][j];
            }
        }
        return (int)lookup[n][m];
    }
};