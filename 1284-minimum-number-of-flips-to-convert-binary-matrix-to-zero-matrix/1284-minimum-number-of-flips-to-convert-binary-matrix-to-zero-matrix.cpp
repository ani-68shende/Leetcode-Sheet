class Solution {
public:
    
    //how to loop is the game 
    
    bool isTrue(vector<vector<int>>& mat){
        int sum = 0;
        for(auto x : mat)
            for(auto y : x)
                sum += y;
        return sum == 0;
    }
    vector<vector<int>> toggler(int i1, int j1, vector<vector<int>> & mat){
        mat[i1][j1] ^= 1;
        if(i1-1>=0){
            mat[i1-1][j1] ^= 1;
        }
        if(i1+1<mat.size()){
            mat[i1+1][j1] ^= 1;
        }
        if(j1-1>=0){
            mat[i1][j1-1] ^= 1;
        }
        if(j1+1< mat[0].size()){
            mat[i1][j1+1] ^= 1;
        }
        return mat;
    }
    int ans = 0;
    int f(int x, int y, vector<vector<int>> mat){
        if(x == mat.size()){
            x = 0, y++; // start again from the next row
        }
        if(y == mat[0].size()){
            if(isTrue(mat)){
                return 0;
            }
            return 1e8;
        }
        int nahi_lera_ja = 0 + f(x+1, y, mat);
        int leke_jara_ja = 1 + f(x+1, y, toggler(x, y, mat));
        return min(nahi_lera_ja, leke_jara_ja);
    }
    int minFlips(vector<vector<int>>& mat) {
        int z = f(0, 0, mat);
        return z == 1e8 ? -1 : z;
    }
};