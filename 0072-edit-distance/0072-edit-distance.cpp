class Solution {
public:
    int minDistance(string text1, string text2) {
        int n = text1.size(), m= text2.size(); 
        vector<vector<int>> lookup(n+1, vector<int>(m+1, 0));
        for (int k = 0; k <= n; k++) lookup[k][0] = k;
        for (int k = 0; k <= m; k++) lookup[0][k] = k;
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(text1[i-1] == text2[j-1])
                    lookup[i][j] = 0 + lookup[i-1][j-1];
                else
                    lookup[i][j] = 1 + min({lookup[i-1][j], lookup[i][j-1], lookup[i-1][j-1]});
            }
        }
        return lookup[n][m];
    }
};