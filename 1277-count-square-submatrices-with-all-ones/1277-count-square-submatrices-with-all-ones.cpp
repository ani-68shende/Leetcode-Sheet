class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int co = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = matrix.size() - 2 ; i >= 0 ; i--){
            for(int j = matrix[0].size() - 2; j >=0 ; j--){
                if(matrix[i][j]==1){
                    matrix[i][j] = 1 + min({matrix[i+1][j], matrix[i][j+1], matrix[i+1][j+1]});
                }
            }
        }
        for(auto x : matrix){
            for(auto y : x)co += y;
        }
        return co;
    }
};