class Solution {
public:
    // will do later again
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int r,int c,queue<pair<int,int>>& qu)
    {
        qu.push({r,c});
    
        
        vis[r][c]=10;
        
        int row[]={1,-1,0,0};
        int col[]={0,0,1,-1};
        
        for(int i=0;i<4;i++)
        {
           int newr=r+row[i],newc=c+col[i];
            
       if(newr>=0&&newr<grid.size()&&newc>=0&&newc<grid[0].size()&&!vis[newr][newc]&&grid[newr][newc])
       {
           dfs(grid,vis,newr,newc,qu);
       }
            
        }
        
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> qu;
        
        int rows=grid.size(),cols=grid[0].size();
        
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        
        for(int r=0;r<rows;r++)
        {
            int c;
            for( c=0;c<cols;c++)
            {
                if(grid[r][c]){
                    dfs(grid,vis,r,c,qu);
                    break;
                }
            }
            
            if(c!=cols)break;
        }
        
        int level=0;
        
        while(qu.size())
        {
            
            auto siz=qu.size();
            
            while(siz--)
            {
            
            auto er=qu.front();
            auto x=er.first;
            auto y=er.second;

            qu.pop();
            
            if(vis[x][y]==0)
            {

                if(grid[x][y])
                    return level-1;
            }
            else if(vis[x][y]==1)
                    continue;
                
            int row[]={1,-1,0,0};
            int col[]={0,0,1,-1};
            
           for(int i=0;i<4;i++)
           {
            
               int nr=row[i]+x;
               int nc=col[i]+y;
               
               if(nr>=0&&nr<grid.size()&&nc>=0&&nc<grid[0].size()&&vis[nr][nc]!=1)
               {        

                   qu.push({nr,nc});
                
                }
               
           }
                
            vis[x][y]=1;
            
            
            }
            
            level++;
            
        }
        
        return 19;
    }
};