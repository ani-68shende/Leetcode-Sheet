class Solution {
public:
    
    bool isValid(int i, int j, vector<vector<char>>& board, char ch){
        int k = 0;
        int n = board.size();
        for(int k = 0 ; k < n ; k++){
            if(board[k][j] == ch)return false;
            if(board[i][k] == ch)return false;
            if(board[3*(i/3) + k/3][3*(j/3) + k%3] == ch)return false;
        }
        return true;
    }
    // direct jump
    bool solve(vector<vector<char>>& board){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.'){
                    for(int k = '1' ; k <= '9' ; k++){
                        if(isValid(i, j, board, k)){
                            board[i][j] = k;
                            if(solve(board))return true;
                            else
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }            
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};