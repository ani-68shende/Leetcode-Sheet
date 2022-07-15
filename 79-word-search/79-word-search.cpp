class Solution {
public:
    int n, m, vv;
    bool dfs(int i, int j, vector<vector<char>>& board, string word){
        if(word.size() == 0)return true;
        if(i < 0 || j < 0 || i >= n || j >= m || word[0] != board[i][j]){
            return false;
        }
        char ch = board[i][j];
        string new_word = word.substr(1);
        board[i][j] = '$';
        bool flag = dfs(i + 1, j, board, new_word) || dfs(i, j + 1, board, new_word) || dfs(i, j - 1, board, new_word) || dfs(i - 1, j, board, new_word);
        board[i][j] = ch;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vv = word.size();
        bool g = false;
        n = board.size();
        m = board[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(dfs(i, j, board, word))return true;
            }
        }
        return false;
    }
};