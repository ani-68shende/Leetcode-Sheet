class Solution {
public:
    int findDiagonalOrder(vector<vector<int>>& mat) {
        int maxu = 0;
        int n = mat.size(); 
        int m = mat[0].size();
        for(int i = 0 ; i < m ; i++){
            int x = 0;
            int y = i;
            int count = 0;
            while(x < n and y >= 0){
                if(mat[x][y] == 1){
                    count++;
                }else{
                    count = 0;
                }
                maxu = max(maxu, count);
                x++;y--;
            }
        }
        for(int i = 1 ; i < n ; i++){
            int x = i;
            int y = m-1;
            int count = 0;
            while(x < n and y >= 0){
                if(mat[x][y] == 1){
                    count++;
                }else{
                    count = 0;
                }
                maxu = max(maxu, count);
                x++;y--;
            }
        }
        return maxu;
    }

    int longestLine(vector<vector<int>>& mat) {
        int maxu = 0;
        int n = mat.size(); 
        int m = mat[0].size();
        for(int i = 0 ; i < n ; i++){
            int count = 0;
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 1){
                    count++;
                }else{
                    count = 0;
                }
                maxu = max(maxu, count);
            }
        }
        for(int i = 0 ; i < m ; i++){
            int count = 0;
            for(int j = 0 ; j < n ; j++){
                if(mat[j][i] == 1){
                    count++;
                }else{
                    count = 0;
                }
                maxu = max(maxu, count);
            }
        }
        
        maxu = max(maxu, findDiagonalOrder(mat));
        for(int i = 0 ; i < n ; i++)
            reverse(mat[i].begin(), mat[i].end());
        maxu = max(maxu, findDiagonalOrder(mat));
            
        return maxu;
    }
};