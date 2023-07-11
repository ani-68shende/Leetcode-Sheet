class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>v;
        int maxu = 0;
        int n = mat.size(); 
        int m = mat[0].size();
        int flag = 1;
        for(int i = 0 ; i < m ; i++){
            int x = 0;
            int y = i;
            vector<int>temp;
            while(x < n and y >= 0){
                temp.push_back(mat[x][y]);
                x++;y--;
            }
            if(flag)
                reverse(temp.begin(), temp.end());
            for(int j = 0 ; j < temp.size() ; j++){
                v.push_back(temp[j]);
            }
            flag ^=1 ;
        }
        for(int i = 1 ; i < n ; i++){
            int x = i;
            int y = m-1;
            vector<int>temp;
            while(x < n and y >= 0){
                temp.push_back(mat[x][y]);
                x++;y--;
            }
            if(flag)
                reverse(temp.begin(), temp.end());
            for(int j = 0 ; j < temp.size() ; j++){
                v.push_back(temp[j]);
            }
            flag ^=1 ;
        }
        return v;
    }
};