class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> board(8, vector<int>(8, 0));
        board[king[0]][king[1]] = -1;
        for(auto x : queens){
            board[x[0]][x[1]] = 1;
        }
        vector<vector<int>>ans;
        int x, y;
        x = king[0], y = king[1];
        while(x>=0){
            if(board[x][y] == 1){
                ans.push_back({x, y});
                break;
            }    
            x--;
        }
        x = king[0], y = king[1];
        while(y>=0){
            if(board[x][y] == 1){
                ans.push_back({x, y});
                break;
            }    
            y--;
        }
        x = king[0], y = king[1];
        while(y<8){
            if(board[x][y] == 1){
                ans.push_back({x, y});
                break;
            }    
            y++;
        }
        x = king[0], y = king[1];
        while(x<8){
            if(board[x][y] == 1){
                ans.push_back({x, y});
                break;
            }    
            x++;
        }
        x = king[0], y = king[1];
        while(x>=0 && y>=0){
            if(board[x][y] == 1){
                ans.push_back({x, y});
                break;
            }    
            x--;
            y--;
        }
        x = king[0], y = king[1];
        while(x<8 && y>=0){
            if(board[x][y] == 1){
                ans.push_back({x, y});
                break;
            }    
            x++;
            y--;
        }
        x = king[0], y = king[1];
        while(x>=0 && y<8){
            if(board[x][y] == 1){
                ans.push_back({x, y});
                break;
            }    
            x--;
            y++;
        }
        x = king[0], y = king[1];
        while(x<8 && y<8){
            if(board[x][y] == 1){
                ans.push_back({x, y});
                break;
            }    
            x++;
            y++;
        }
        return ans;
    }
};