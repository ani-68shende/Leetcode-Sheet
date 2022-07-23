class Solution {
public:
    bool isValid(int row, int col, vector<string> board){
        int r = row;
        int c = col;
        int n = board.size();
        while(r >= 0 && c >=0){
            if(board[r][c] == 'Q')return false;
            r--;
            c--;
        }
        r = row;
        c = col;
        while(r < n && c >= 0){
            if(board[r][c] == 'Q')return false;
            r++;
            c--;
        }
        r = row;
        c = col;
        while(c >= 0){
            if(board[r][c] == 'Q')return false;
            c--;
        }
        return true;
    }
    void solve(int col, vector<string>&board, int n, vector<vector<string>>& ans){
        if(col == n){
            ans.push_back(board);
            return ;
        }
        for(auto i = 0 ; i < n ; i++){
            if(isValid(i, col, board)){
                board[i][col] = 'Q';
                solve(col+1, board, n, ans);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string ss(n, '.');
        for(int i = 0 ; i < n ; i++){
            board[i] = ss;
        }
        vector<vector<string>>ans;
        solve(0, board, n, ans);    
        return ans;
    }
};