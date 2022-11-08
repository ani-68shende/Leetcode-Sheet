class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n(mat.size());
        int m(mat[0].size());
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int flag = 0;
                if(i+1 < n){
                    if(mat[i+1][j] < mat[i][j])
                        flag++;
                }else if(i+1 >= n)flag++;
                
                if(j+1 < m){
                    if(mat[i][j+1] < mat[i][j])
                        flag++;
                }else if(j+1 >= m)flag++;
                
                if(i-1 >= 0){
                    if(mat[i-1][j] < mat[i][j])
                        flag++;
                }else if(i-1<0)flag++;
                
                if(j-1 >= 0){
                    if(mat[i][j-1] < mat[i][j])
                        flag++;
                }else if(j-1<0)flag++;
                if(flag == 4)return {i,j};
            }
        }
        return {0,0};
    }
};