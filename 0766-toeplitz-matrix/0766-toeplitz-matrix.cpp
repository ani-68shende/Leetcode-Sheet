class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool flag = true;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 || j == 0){
                    int x = i;
                    int y = j;
                    int val = matrix[i][j];
                    while(x < n && y < m){
                        if(matrix[x][y] != val)
                            flag = false;
                        x++,y++;
                    }
                }
            }
        }
        return flag;
    }
};