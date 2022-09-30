class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum(0);
        int n = mat.size();
        int j = 0;
        for(int i = 0 ; i < n ; i++){
            sum += mat[i][j];
            j++;
        }
        j = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            sum += mat[i][j];
            j++;
        }
        if(n&1)sum-=mat[n/2][n/2];
        return sum;
    }
};