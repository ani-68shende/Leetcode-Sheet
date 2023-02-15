class Solution {
public:
    int n, m;
    vector<vector<int>>dp;
    void NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        n++,
        m++;
        dp.resize(n, vector<int>(m, 0));
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                dp[i][j] += matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                // cout << dp[i][j] << " ";
            }
            // cout << "\n";
        }
        // for(auto &x: dp){
        //     for(auto &y: x){
        //         cout << y << " ";
        //     }
        //     cout << "\n";
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row2+1][col1]-dp[row1][col2+1]+dp[row1][col1];
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  
        NumMatrix(matrix);
        int count = 0;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                for(int k = i ; k < matrix.size() ; k++){
                    for(int l = j ; l < matrix[0].size() ; l++){
                        if(sumRegion(i, j, k, l)==target)count++;
                    }
                }
            }
        }
        return count;
    }
};