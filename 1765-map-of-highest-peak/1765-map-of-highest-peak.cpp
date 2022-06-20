class Solution {
public:
    // the most imp and OP step in this question is the assigning of -1 in the 0's position and assigning 0 in 1's position
    vector<vector<int>> highestPeak(vector<vector<int>>&wa) {
        int n = wa.size();
        int m = wa[0].size();
        vector<vector<int>>v(n, vector<int>(m,0));
        queue<pair<int, int>>q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(wa[i][j] == 1){
                    v[i][j] = 0;
                    q.push({i, j});
                }else{
                    v[i][j] = -1;
                }
            }
        }
        vector<int>x{0,1,0,-1};
        vector<int>y{1,0,-1,0};
        while(!q.empty()){
            auto fron = q.front();
            q.pop();
            int r = fron.first;
            int c = fron.second;
            for(int i = 0 ; i < 4 ; i++){
                int nr = r+x[i];
                int nc = c+y[i];
                if(nr >=0 && nr < n && nc >= 0 && nc < m && v[nr][nc]==-1){
                    v[nr][nc] = v[r][c]+1;
                    q.push({nr, nc});
                }
            }
        }
        return v;
    }
};