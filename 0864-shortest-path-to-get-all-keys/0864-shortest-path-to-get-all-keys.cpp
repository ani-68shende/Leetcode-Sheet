class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int countkeys = 0, startx = -1, starty = -1, m = grid.size(), n = grid[0].size(), countsteps = 0;
        
        
        
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == '@'){
                    startx = i, starty = j;
                }
                if(grid[i][j] >= 'a' and grid[i][j] <= 'z'){
                    countkeys++;
                }
            }
        }
        
        
        
        int finalMask = (1<<countkeys)-1;
        
        
        
        queue<vector<int>>q;
        vector<vector<vector<int>>> memo(m,vector<vector<int>>(n, vector<int>(finalMask+1,0)));
        vector<int> dir{-1,0,1,0,-1};
        
        
        q.push({startx, starty, 0});
        memo[startx][starty][0] = 1;
        
        
        //bfs
        while(q.size()){
            
            int siz = q.size();
            
            for(int i = 0 ; i < siz ; i++){
                auto fron = q.front();
                q.pop();
                int x = fron[0], y = fron[1], mask = fron[2];
                if(mask == finalMask){
                    return countsteps;
                }
                for(int j = 0 ; j < 4 ; j++){
                    //additional feature
                    int newmask = mask;
                    
                    int newx = x + dir[j], newy = y + dir[j+1];
                        
                    //out of bounds
                    if(newx < 0 || newy < 0 || newx >= grid.size() || newy >= grid[0].size()){
                        continue;
                    }
                    
                    //if wall
                    if(grid[newx][newy] == '#'){
                        continue;
                    }
                    
                    //if lock and key not yet found
                    if(grid[newx][newy] >= 'A' and grid[newx][newy] <= 'Z'){
                        int lockid = grid[newx][newy] - 'A';
                        if((newmask & (1 << lockid)) == 0){
                            continue;
                        }
                        // cout << newx << " " << newy << endl;
                    }
                    
                    //if key found
                    if(grid[newx][newy] >= 'a' and grid[newx][newy] <= 'z'){
                        int lockid = grid[newx][newy] - 'a';
                        newmask |= (1 << lockid);
                    }
                    
                    //already visited
                    if(memo[newx][newy][newmask] == 1){
                        continue;
                    }
                    
                    q.push({newx, newy, newmask});
                    memo[newx][newy][newmask] = 1;
                }
            }
            countsteps+=1;
        }
        return -1;
    }
};