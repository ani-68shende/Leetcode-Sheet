class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long sum = 0;
        unordered_set<string>s;
        for(auto x : ideas)s.insert(x);
        vector<vector<int>>board(26, vector<int>(26, 0));
        for(auto x : ideas){
            string temp = x;
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                temp[0] = ch;
                if(!s.count(temp)){
                    board[x[0]-'a'][ch-'a']++;
                }
            }
        }
        for(int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < 26 ; j++){
                sum += 1LL*board[i][j]*board[j][i];
            }
        }
        return sum;
    }
};