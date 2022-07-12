class Solution {
public:
    int N, M;
    void dfs(int i, int j, vector<vector<char>>& board){
        if(i < 0 || j < 0 || i >= N || j >= M || board[i][j] == '.')return ;
        board[i][j] = '.';
        dfs(i+1, j, board);
        dfs(i-1, j, board);
        dfs(i, j+1, board);
        dfs(i, j-1, board);
    }
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        N = board.size();
        M = board[0].size();
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(board[i][j] == 'X'){
                    count++;
                    dfs(i, j, board);
                }
            }
        }
        return count;
    }
};