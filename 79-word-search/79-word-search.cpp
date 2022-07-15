class Solution {
public:
    int n, m, vv;
    bool dfs(int i, int j, vector<vector<char>>& board, string &word, string& temp, int idx){
        if(temp == word)return true;
        if(temp.size() > min(vv, 15) || i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[idx]){
            return false;
        }
        char ch = board[i][j];
        temp.push_back(ch);
        board[i][j] = '$';
        bool flag = dfs(i + 1, j, board, word, temp, idx+1) || dfs(i, j + 1, board, word, temp, idx+1) || dfs(i, j - 1, board, word, temp, idx+1) || dfs(i - 1, j, board, word, temp, idx+1);
        //temp.pop_back();
        temp.pop_back();
        board[i][j] = ch;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool g = false;
        vv = word.size();
        n = board.size();
        m = board[0].size();
        string temp = "";
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(dfs(i, j, board, word, temp, 0))return true;
            }
        }
        return false;
    }
};