class Solution {
public:
    vector<int>dir{0,1,0,-1,0};
    // mid is the limit to which we need to take the cells
    bool helper(int row, int col, vector<vector<int>> & cells, int mid){
        vector<vector<int>>grid(row, vector<int>(col, 0));
        for(int i = 0 ; i < mid ; i++){
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        queue<pair<int, int>>q;
        for(int i = 0 ; i < grid[0].size() ; i++){
            if(grid[0][i] == 0){
                q.push({0, i});
                grid[0][i] = 1;
            }
        }
        while(!q.empty()){
            pair<int, int> fron = q.front();
            int x = fron.first;
            int y = fron.second;
            if(x == row-1)return true;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int x1 = x+dir[i];
                int y1 = y+dir[i+1];
                if(x1 < 0 || y1 < 0 || x1 >= row || y1 >= col || grid[x1][y1] == 1)continue;
                grid[x1][y1] = 1;
                q.push({x1,y1});
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 1;
        int high = row*(col);
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(helper(row, col, cells, mid)){
                ans = mid;
                low = mid+1;
            }else{
                high= mid-1;
            }
        }
        return ans;
    }
};